//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#include "Trie.h"

//Open the gate :)
//Return pointer to new trieNode
trieNode *newNode() {
	trieNode *tmp = new trieNode;
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
	return -1;
}

bool IsNumber(char key) //check the character after "." is a number
{
	if (key >= 48 && key <= 57) return true;
	return false;
}

//split long string into individual words
//Insert a word to trie
void CreateTrieTree(trieNode *&root, string key) {
	trieNode *cur = root;
	for (int i = 0; i < key.length()-1; ++i)
	{
		int index = charToIndex(key[i]);
		if (!cur->next[index]) { //cur->next[index] == NULL, this gate hasn't been opened yet, open
			cur->next[index] = newNode();
		}
		cur = cur->next[index];
	}
	//when i runs to the end of the key, mark leaf node
	cur->isLeaf = true;
}

//Search for a key, return TRUE if 'key' in the trie else return FALSE
bool Searching(trieNode* root, string key) {
	trieNode *cur = root;
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

void DataTree(trieNode *&root, ifstream &fin)
{
	string sentence;
	string keys[50];
	getline(fin, sentence, '\n'); //get the title
	while (!fin.eof())
	{
		getline(fin, sentence, '.'); //get a sentence
		if (sentence.length() && IsNumber(sentence.back())) //before "." is a number
		{
			string tmp;
			getline(fin, tmp, '.');
			if (tmp.length() && IsNumber(tmp[0])) //after "." is a number, then it's a decimal, combine them
			{
				sentence += tmp;
				SentenceTree(root, sentence);
				continue;
			}
			else //if not, they are 2 different sentences, build 2 trees
			{
				SentenceTree(root, sentence);
				SentenceTree(root, tmp);
				continue;
			}
		}
		SentenceTree(root, sentence); //nothing happened, we build the tree directly
	}
}
void SentenceTree(trieNode *&root, string sen)
{
	//split a string containing whitespace into a keys[] by singleWords
	int i = 0;
	string keys[100];
	stringstream ss(sen);
	string singleWord;
	while (ss >> singleWord)
		keys[i++] = singleWord;

	//build our trie^^
	int n = sizeof(keys) / sizeof(keys[0]);
	for (int j = 0; j < i; ++j) {
		CreateTrieTree(root, keys[j]);
	}
}
