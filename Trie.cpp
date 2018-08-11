//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#include "Trie.h"

//Open the gate :)
//Return pointer to new trieNode
trieNode* newNode() {
	trieNode* tmp = new trieNode;   //when can I deallocate this pointer?
	tmp->isLeaf = false;
	for (int i = 0; i < refSize; ++i) {
		tmp->next[i] = NULL;
	}
	return tmp;
}

//ASCII: '0' = 48, '9' = 57, A = 65, Z = 90, a = 97, z = 122
//0-9: '0' - '9'; 10-35: 'a' - 'z'; 36: whiteSpace; 37: '.' dot; 38: '$'; 39: '%'; 40: '#'; 41: '-'
int charToIndex(char c) {
	if (c >= 48 && c <= 57) return (c - '0');
	if (c >= 97 && c <= 122) return (int(c) - 87);
	if (c >= 65 && c <= 90) return (int(c) - 55);
	if (c == ' ') return 36;
	if (c == '.') return 37;
	if (c == '$') return 38;
	if (c == '%') return 39;
	if (c == '#') return 40;
	if (c == '-') return 41;
	return 36;//36 to store special characters that a
}

//split long string into individual words

//Insert a word to trie
void insert(trieNode *&root, string key) { //fix by AT
	trieNode* cur = root;
	for (int i = 0; i < key.length(); ++i) {
		//int index = key[i] - 'a';  //I've already had function to convert - modify later
		int index = charToIndex(key[i]);//i-1
		if (!cur->next[index] && index < 42) { //cur->next[index] == NULL, this gate hasn't been opened yet, open
			cur->next[index] = newNode();
		}
		cur = cur->next[index];
	}
	//when i runs to the end of the key, mark leaf node
	cur->isLeaf = true;
}

//Search for a key, return TRUE if 'key' in the trie else return FALSE
bool search(trieNode* root, string key) {
	trieNode* cur = root;
	for (int i = 0; i < key.length(); ++i) {
		//int index = key[i] - 'a';
		int index = charToIndex(key[i]);
		if (!cur->next[index]) {
			return false;
		}
		cur = cur->next[index];
	}
	if (cur && cur->isLeaf)
		return true;
	else
		return false;
}

//compare score to sort the display vector
bool scoreCompare(const displayedItem &item1, const displayedItem &item2) {
	return item1.score > item2.score;
}

//highlight keyword with bright color then convert to the normal color
void makeColor(int colorCode) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

//cout a sentence with keyword highlighted
void highLight(string sentence, string keyword) {
	string tmpSentence = sentence;
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
	std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
	int subStringPos = tmpSentence.find(keyword); //return the position from which Key and Sentence matches

	for (int i = 0; i < subStringPos; ++i) {
		cout << sentence[i];
	}
	for (int i = subStringPos; i < subStringPos + keyword.size(); ++i) {
		makeColor(14);
		cout << sentence[i];
	}
	makeColor(7);
	for (int i = subStringPos + keyword.size(); i < sentence.size(); ++i) {
		cout << sentence[i];
	}
}

//highlight title different a little
void highLightTitle(string sentence, string keyword) {
	string tmpSentence = sentence;
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
	std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
	int subStringPos = tmpSentence.find(keyword); //return the position from which Key and Sentence matches
	makeColor(3);
	for (int i = 0; i < subStringPos; ++i) {
		cout << sentence[i];
	}
	for (int i = subStringPos; i < subStringPos + keyword.size(); ++i) {
		makeColor(14);
		cout << sentence[i];
	}
	makeColor(3);
	for (int i = subStringPos + keyword.size(); i < sentence.size(); ++i) {
		cout << sentence[i];
	}
	cout << endl;
}

//highlight title AND
void highLightTitleAND(string sentence, string key1, string key2) {
	string tmpSentence = sentence;
	//std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
	std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
	int subStringPos1 = tmpSentence.find(key1); //return the position from which Key and Sentence matches
	int subStringPos2 = tmpSentence.find(key2);
	makeColor(3);
	if (subStringPos1 && subStringPos2) {
		for (int i = 0; i < subStringPos1; ++i) {
			cout << sentence[i];
		}
		makeColor(14);
		for (int i = subStringPos1; i < subStringPos1 + key1.size(); ++i) {
			makeColor(14);
			cout << sentence[i];
		}
		makeColor(3);
		for (int i = subStringPos1 + key1.size(); i < subStringPos2; ++i) {
			cout << sentence[i];
		}
		makeColor(14);
		for (int i = subStringPos2; i < subStringPos2 + key2.size(); ++i) {
			cout << sentence[i];
		}
		makeColor(3);
		for (int i = subStringPos2 + key2.size(); i < sentence.size(); ++i) {
			cout << sentence[i];
		}
		makeColor(7);
	}

	//cout << sentence;
	makeColor(7);
	cout << endl;
}

//highlightAND
void highLightAND(string sentence, string key1, string key2) {
	string tmpSentence = sentence;
	std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
	int subStringPos1 = tmpSentence.find(key1); //return the position from which Key and Sentence matches
	int subStringPos2 = tmpSentence.find(key2);

	if (subStringPos1 != -1 && subStringPos1 < subStringPos2) {

		for (int i = 0; i < subStringPos1; ++i) {
			cout << sentence[i];
		}
		for (int i = subStringPos1; i < subStringPos1 + key1.size(); ++i) {
			makeColor(14);
			cout << sentence[i];
		}
		makeColor(7);
		for (int i = subStringPos1 + key1.size(); i < subStringPos2; ++i) {
			cout << sentence[i];
		}
		makeColor(14);
		for (int i = subStringPos2; i < subStringPos2 + key2.size(); ++i) {
			cout << sentence[i];
		}
		makeColor(7);
		for (int i = subStringPos2 + key2.size(); i < sentence.size(); ++i) {
			cout << sentence[i];
		}
	}
	cout << endl;
}

// highlight title OR
void highLightTitleOR(string sentence, string key1, string key2) {
	string tmpSentence = sentence;
	//std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
	std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
	int subStringPos1 = tmpSentence.find(key1); //return the position from which Key and Sentence matches
	int subStringPos2 = tmpSentence.find(key2);
	makeColor(3);
	if (subStringPos1 || subStringPos2) {
		for (int i = 0; i < subStringPos1; ++i) {
			cout << sentence[i];
		}
		makeColor(14);
		for (int i = subStringPos1; i < subStringPos1 + key1.size(); ++i) {
			makeColor(14);
			cout << sentence[i];
		}
		makeColor(3);
		for (int i = subStringPos1 + key1.size(); i < subStringPos2; ++i) {
			cout << sentence[i];
		}
		makeColor(14);
		for (int i = subStringPos2; i < subStringPos2 + key2.size(); ++i) {
			cout << sentence[i];
		}
		makeColor(3);
		for (int i = subStringPos2 + key2.size(); i < sentence.size(); ++i) {
			cout << sentence[i];
		}
		makeColor(7);
	}

	//cout << sentence;
	makeColor(7);
	cout << endl;
}


//highlightOR
void highLightOR(string sentence, string key1, string key2) {
	string tmpSentence = sentence;
	std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
	int subStringPos1 = tmpSentence.find(key1); //return the position from which Key and Sentence matches
	int subStringPos2 = tmpSentence.find(key2);

	if (subStringPos1 != -1 || subStringPos2 != -1) {

		for (int i = 0; i < subStringPos1; ++i) {
			cout << sentence[i];
		}
		for (int i = subStringPos1; i < subStringPos1 + key1.size(); ++i) {
			makeColor(14);
			cout << sentence[i];
		}
		makeColor(7);
		for (int i = subStringPos1 + key1.size(); i < subStringPos2; ++i) {
			cout << sentence[i];
		}
		makeColor(14);
		for (int i = subStringPos2; i < subStringPos2 + key2.size(); ++i) {
			cout << sentence[i];
		}
		makeColor(7);
		for (int i = subStringPos2 + key2.size(); i < sentence.size(); ++i) {
			cout << sentence[i];
		}
	}
	cout << endl;
}


void generateKey(string searchkey, string &key1, string &key2) {
	string tmpSearchkey = searchkey;
	std::transform(tmpSearchkey.begin(), tmpSearchkey.end(), tmpSearchkey.begin(), ::tolower);
	int subStringPos = tmpSearchkey.find("and"); //return the position from which "AND" and tmpSearchkey match
	key1 = tmpSearchkey.substr(0, subStringPos - 1);
	key2 = tmpSearchkey.substr(subStringPos + 4, tmpSearchkey.size() - 1);

	cout << endl << "Key1: " << key1 << endl << "Key2: " << key2 << endl;
}

void searchWithAND(string key1, string key2, vector<displayedItem> &display) {
	ifstream fin;
	string FileName;
	for (int groupName = 1; groupName < 3; ++groupName) {//only two group for checking
		for (int j = 1; j <= 100; j++)
		{

			FileName = CreateFileName(groupName, j); //go to CreateFileName function
			fin.open(FileName);
			if (!fin.is_open())
			{
				cout << "Can't open file " << FileName << endl; //can't open file---------------------------------------
				continue;
			}
			//cout << FileName << endl;
			else {
				string sentence;
				displayedItem item;

				getline(fin, sentence, '\n'); //get the title
				string titleOfficial = sentence;//std::string(title);
				while (!fin.eof())
				{
					getline(fin, sentence, '.'); //get a sentence
					string tmpSentence = sentence;
					std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
					//WILD CARD
					int subStringPos1 = tmpSentence.find(key1); //return the position from which Key and Sentence match
					int subStringPos2 = tmpSentence.find(key2);
					//if (subStringPos1 != string::npos && subStringPos2 != string::npos) {
					if (subStringPos1 != -1 && subStringPos2 != -1) {
						item.title = titleOfficial;
						item.fileName = FileName;
						item.sentenceContainKey = sentence;
						++item.score;  //lack: if a sentence contain more than one key
					}

				}
				if (item.score > 0) {
					transform(item.title.begin(), item.title.end(), item.title.begin(), ::toupper);
					display.push_back(item);
				}

			}
			fin.close();
		}
	}

	sort(display.begin(), display.end(), scoreCompare);
	if (display.size() >= 5) {
		for (int i = 0; i < 5; ++i) {  //display.size() must be greater than 5
			makeColor(3); //dark blue
			highLightTitleAND(display[i].title, key1, key2);
			makeColor(7);
			cout << "\"...";
			highLightAND(display[i].sentenceContainKey, key1, key2);
			cout << "...\"" << endl << endl
				<< "_From file: " << display[i].fileName << endl
				<< "_Score: " << display[i].score << endl << endl << endl << endl << endl;
		}
	}
	else {
		for (int i = 0; i < display.size(); ++i) {  //display.size() < 5
			makeColor(3); //dark blue
			highLightTitleAND(display[i].title, key1, key2);
			makeColor(7);
			cout << "\"...";
			highLightAND(display[i].sentenceContainKey, key1, key2);
			cout << "...\"" << endl << endl
				<< "_From file: " << display[i].fileName << endl
				<< "_Score: " << display[i].score << endl << endl << endl << endl << endl;

		}
	}
}



void generateKeyOR(string searchkey, string &key1, string &key2) {
	string tmpSearchkey = searchkey;
	int subStringPos = tmpSearchkey.find("or"); //return the position from which "OR" and tmpSearchkey match
	key1 = tmpSearchkey.substr(0, subStringPos - 1);
	key2 = tmpSearchkey.substr(subStringPos + 3, tmpSearchkey.size() - 1);

	cout << endl << "Key1: " << key1 << endl << "Key2: " << key2 << endl;

}

void searchWithOR(string key1, string key2, vector<displayedItem> &display) {
	ifstream fin;
	string FileName;
	for (int groupName = 1; groupName < 3; ++groupName) {//only two group for checking
		for (int j = 1; j <= 100; j++)
		{

			FileName = CreateFileName(groupName, j); //go to CreateFileName function
			fin.open(FileName);
			if (!fin.is_open())
			{
				cout << "Can't open file " << FileName << endl; //can't open file---------------------------------------
				continue;
			}
			//cout << FileName << endl;
			else {
				string sentence;
				displayedItem item;

				getline(fin, sentence, '\n'); //get the title
				string titleOfficial = sentence;//std::string(title);
				while (!fin.eof())
				{
					getline(fin, sentence, '.'); //get a sentence
					string tmpSentence = sentence;
					std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
					//WILD CARD
					int subStringPos1 = tmpSentence.find(key1); //return the position from which Key and Sentence match
					int subStringPos2 = tmpSentence.find(key2);
					//if (subStringPos1 != string::npos && subStringPos2 != string::npos) {
					if (subStringPos1 != -1 || subStringPos2 != -1) {
						item.title = titleOfficial;
						item.fileName = FileName;
						item.sentenceContainKey = sentence;
						++item.score;  //lack: if a sentence contain more than one key
					}

				}
				if (item.score > 0) {
					transform(item.title.begin(), item.title.end(), item.title.begin(), ::toupper);
					display.push_back(item);
				}

			}
			fin.close();
		}
	}

	sort(display.begin(), display.end(), scoreCompare);
	if (display.size() >= 5) {
		for (int i = 0; i < 5; ++i) {  //display.size() must be greater than 5
			makeColor(3); //dark blue
			highLightTitleOR(display[i].title, key1, key2);
			makeColor(7);
			cout << "\"...";
			highLightOR(display[i].sentenceContainKey, key1, key2);
			cout << "...\"" << endl << endl
				<< "_From file: " << display[i].fileName << endl
				<< "_Score: " << display[i].score << endl << endl << endl << endl << endl;
		}
	}
	else {
		for (int i = 0; i < display.size(); ++i) {  //display.size() < 5
			makeColor(3); //dark blue
			highLightTitleAND(display[i].title, key1, key2);
			makeColor(7);
			cout << "\"...";
			highLightAND(display[i].sentenceContainKey, key1, key2);
			cout << "...\"" << endl << endl
				<< "_From file: " << display[i].fileName << endl
				<< "_Score: " << display[i].score << endl << endl << endl << endl << endl;

		}
	}
}

//Retrieval process: find out files that contains the found KEY/QUERY
void retrieval(string key, vector<displayedItem> &display, bool check, bool exact)
{
	ifstream fin;
	string FileName;
	//for (int i = 1; i <= 25; i++)
	for (int groupName = 1; groupName < 6; ++groupName) {//only two group for checking
		for (int j = 1; j <= 100; j++)
		{
			FileName = CreateFileName(groupName, j); //go to CreateFileName function
			fin.open(FileName);
			if (!fin.is_open())
			{
				cout << "Can't open file " << FileName << endl; //can't open file---------------------------------------
				continue;
			}
			//cout << FileName << endl;
			else {
				string sentence;
				displayedItem item; int itemIndex = 0;
				getline(fin, sentence, '\n'); //get the title
				string titleOfficial = sentence;
				string tmpSentence = sentence;
				std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
				int subStringPos = tmpSentence.find(key);

				if (subStringPos != string::npos) {
					item.title = titleOfficial;
					++item.score;
				}
				while (!fin.eof())
				{
					getline(fin, sentence, '.'); //get a sentence
					tmpSentence = sentence;
					std::transform(key.begin(), key.end(), key.begin(), ::tolower);
					//cout << "My keyWord after transforming: " << key << endl;
					std::transform(tmpSentence.begin(), tmpSentence.end(), tmpSentence.begin(), ::tolower);
					//WILD CARD
					subStringPos = tmpSentence.find(key); //return the position from which Key and Sentence matches

					if (subStringPos != string::npos) {
						item.title = titleOfficial;
						item.fileName = FileName;
						item.sentenceContainKey = sentence;
						if (!check) {
							++item.score;  //lack: if a sentence contain more than one key
						}

					}

				}
				if (item.score > 0) {
					transform(item.title.begin(), item.title.end(), item.title.begin(), ::toupper);
					display.push_back(item);
				}

			}
			fin.close();
		}
	}

	sort(display.begin(), display.end(), scoreCompare);
	for (int i = 0; i < min(display.size(), 5); ++i) {  //display.size() must be greater than 5
		makeColor(3); //dark blue
		//cout << display[i].title << endl;
		highLightTitle(display[i].title, key);
		makeColor(7);
		cout << "\"...";
		highLight(display[i].sentenceContainKey, key);
		cout << "...\"" << endl << endl
			<< "_From file: " << display[i].fileName << endl
			<< "_Score: " << display[i].score << endl << endl << endl << endl << endl;
	}

}

bool intitle(string& key)
{
	string check = "intitle:";
	if (key.length() < 9) return false;
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (key[i] != check[i]) return false;
		}
	}
	key = key.substr(key.find(":") + 1);
	return true;
}

bool checkexact(string& key)
{
	if (key[0] == '"' && key[key.length() - 1] == '"')
	{
		key = key.substr(key.find('"') + 1);
		key.erase(key.length() - 1, 1);

		return true;
	}
	else return false;
}

void Fullsearch(trieNode *&root, string query)
{
	bool check = intitle(query); //SEARCH INTITLE
	bool exact = checkexact(query);
	bool temp = search(root, query);
	if (exact) temp = true;
	Outputscreen(query, temp, check, exact);
}

void Outputscreen(string query, bool search, bool check, bool exact)
{
	if (!search) { //switch yes & no statement
		makeColor(10);
		cout << endl << "KEYWORD DOES NOT EXIT!" << endl << endl;
		makeColor(7);
	}
	else {
		makeColor(10);
		cout << endl << "SEARCH RESULT(S):" << endl << endl;
		makeColor(7);
		//Display function goes here
		//For each KEY/QUERY, creat a vector of potential displayed items then choose 5 highest score files to display
		vector<displayedItem> display;
		retrieval(query, display, check, exact);
	}
}

bool HasMinus(string query, int &i)
{
	for (i = 0; i < query.size() - 1; i++)
	{
		if (query[i] == ' ' && query[i + 1])
			return true;
	}
	return false;
}

string Removeminus(string query, int i)
{
	string tmp;
	tmp.append(query.begin(), query.begin() + i);
	return tmp;
}

/*bool HasPlus(string query, int &i)
{
for (int i = 0; i < query.size() - 3; i++)
{
if (query[i] == '+' && query[i + 1] == 'a' && query[i + 2] == 'n' && query[i + 3] == 'd')
{
return true;
break;
}
}
return false;
}

string firstplus(string query, int i)
{
string first;
first.append(query.begin(), query.begin() + i);
return first;
}

string lastplus(string query, int i)
{
string last;
last.append(query.begin() + i,query.end());
return last;
}*/

bool isRange(string key, double &low, double &high)
{
	bool check = false;
	int len = key.length();
	string down, up; //store price in string type
	int i; //position of first dot
	for (i = 0; i < len; i++)
	{
		if (key[i] == '.' && key[i + 1] == '.')
		{
			check = true;
			break;
		}
	}
	if (check) {
		for (int j = 0; j < i; j++)
		{
			down += key[j];
		}
		for (int j = i + 2; i < len; j++)
		{
			up += key[j];
		}
		if (key[0] == '$')
		{
			down = down.substr(1, down.length() - 1);
			up = up.substr(1, up.length() - 1);
		}
		// chuyen doi 1 chuoi string hoac char thanh 1 so thuc dau cham dong luu vao mang float
		low = atof(down.c_str());
		high = stof(up.c_str());
	}
	return check;
}