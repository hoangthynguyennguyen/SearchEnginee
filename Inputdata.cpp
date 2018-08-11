#include "Trie.h"

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
	for (int groupName = 1; groupName < 6; ++groupName) { //only two groups for checking
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