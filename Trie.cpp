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

//Retrieval process: find out files that contains the found KEY/QUERY
void retrieval(string key, vector<displayedItem> &display, bool check, bool exact)
{
	ifstream fin;
	string FileName;
	//for (int i = 1; i <= 25; i++)
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
	if (display.size() >= 5) {
		for (int i = 0; i < 5; ++i) {  //display.size() must be greater than 5
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
	else {
		for (int i = 0; i < display.size(); ++i) {  //display.size() < 5
			makeColor(3); //dark blue
			highLightTitle(display[i].title, key);
			makeColor(7);
			cout << "\"...";
			highLight(display[i].sentenceContainKey, key);
			cout << "...\"" << endl << endl
				<< "_From file: " << display[i].fileName << endl
				<< "_Score: " << display[i].score << endl << endl << endl << endl << endl;

		}
	}
}

//Anh Thu
string IntToString(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}


void InputData(trieNode *&root)
{
	ifstream fin;
	string FileName;
	for (int groupName = 1; groupName < 3; ++groupName) { //only two groups for checking
		for (int j = 1; j <= 100; j++)
		{
		
			FileName = CreateFileName(groupName, j); //go to CreateFileName function
			fin.open(FileName);
			if (!fin.is_open())
			{
				cout << "Can't open file " << FileName << endl; //can't open file
				continue;
			}
			//cout << FileName << endl;//-----------------------------------------------------------------------------
			DataTree(root, fin);
			fin.close();
		}
	}
}

string CreateFileName(int i, int j)
{
	string GroupNumber = IntToString(i), TxtNumber = IntToString(j);
	if (1 <= i && i <= 9)
	{
		if (1 <= j && j <= 9)
			return ("Group0" + GroupNumber + "News0" + TxtNumber + ".txt"); //Group01News01.txt
		else
			return ("Group0" + GroupNumber + "News" + TxtNumber + ".txt"); //Group01News10.txt
	}
	else
	{
		if (1 <= j && j <= 9)
			return ("Group" + GroupNumber + "News0" + TxtNumber + ".txt"); //Group10News01.txt
		else
			return ("Group" + GroupNumber + "News" + TxtNumber + ".txt"); //Group10News10.txt
	}
}


bool IsNumber(char key) //check the character after "." is a number
{
	if (key >= 48 && key <= 57) return true;
	return false;
}


void DataTree(trieNode *&root, ifstream &fin)
{
	string sentence;
	getline(fin, sentence, '\n'); //get the title
	SentenceTree(root, sentence); //nothing happened, we build the tree directly
	while (!fin.eof())
	{
		getline(fin, sentence, '.'); //get a sentence
		SentenceTree(root, sentence); //nothing happened, we build the tree directly
	}
}
void SentenceTree(trieNode *&root, string sen)
{
	//split a string containing whitespace into a keys[] by singleWords
	int i = 0;
	string keys[300];
	stringstream ss(sen);
	string singleWord;
	while (ss >> singleWord)
		keys[i++] = singleWord;

	//build our trie^^
	int n = sizeof(keys) / sizeof(keys[0]);
	for (int j = 0; j < i; ++j) {
		insert(root, keys[j]);
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
/*
string cut(string& original)
{
	int i = 0;
	string result;
	while(original[i]!=*" ")
	{
		result[i] = original[i];
	}
	original=
}


*/



































/*

Trie::Trie() {
	root = newNode();
	root->isLeaf = false;
}

trieNode * Trie::newNode() {
	trieNode *trieNodeptr = new trieNode;
	trieNodeptr->id = 0;
	for (int i = 0; i < 42; ++i) {
		trieNodeptr->next[i] = NULL;
	}
	return trieNodeptr;
}


//ASCII: '0' = 48, '9' = 57, A = 65, Z = 90, a = 97, z = 122
int Trie::charToIndex(char c) {
	if (c >= 48 && c <= 57) return (c - '0');
	if (c >= 97 && c <= 122) return (int(c) - 87);
	if (c >= 65 && c <= 90) return (int(c) - 55);
	if (c == ' ') return 36;
	if (c == '.') return 37;
	if (c == '$') return 38;
	if (c == '%') return 39;
	if (c == '#') return 40;
	if (c == '-') return 41;
	return -1;
}


void Trie::push(const char *key, string fileName) {
	trieNode *cur = root;
	string charWord;
	int length = strlen(key);
	for (int i = 0; i < length; ++i) {
		charWord += key[i];
		int index = charToIndex(key[i]);
		if (cur->next[index] == NULL) {
			cur->next[index] = newNode();
		}
		if (cur->data.empty()) {
			cur->data = charWord;
		}
		cur = cur->next[index];
	}
	if (cur->data.empty()) {
		cur->data = charWord;
	}
	cur->id++;
	cur->files.push_back(fileName);
}

bool Trie::searchKey(const char *key) {
	int length = strlen(key);
	trieNode *cur = root;
	int i;
	for (i = 0; i < length; ++i) {
		int index = charToIndex(key[i]);
		if (cur->next[index == NULL]) {
			return false;
		}
		cur = cur->next[index];
	}
	if (cur->id > 0)
		return true;
	else
		return false;
}

vector<string> Trie::searchFile(const char *key) {
	int length = strlen(key);
	trieNode *cur = root;
	int i;
	vector<string> empty;
	for (i = 0; i < length; ++i) {
		int index = charToIndex(key[i]);
		if (cur->next[index] == NULL)
			return empty;
		cur = cur->next[index];
	}
	if (cur->id > 0)
		return cur->files;
	else
		return empty;
}
*/