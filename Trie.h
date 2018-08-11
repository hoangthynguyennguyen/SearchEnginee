//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#ifndef TRIE_H
#define TRIE_H

#include<algorithm>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include<iomanip>
#include<Windows.h>



using namespace std;

const int refSize = 42; //reference size = 42

//Node in trie
struct trieNode {
	//string data;
	//int id;
	trieNode *next[refSize]; //0-9: '0' - '9'; 10-35: 'a' - 'z'; 36: whiteSpace; 37: '.' dot; 38: '$'; 39: '%'; 40: '#'; 41: '-'
	bool isLeaf = false;
	//vector <string> files;
};

//Displayed result 
struct displayedItem {
	string title; //upperCase - code a function to convert lower to uppercase ----------------------------------------
	string sentenceContainKey;
	string fileName; //format txt get from Anh Thu's function
	int score = 0;  //compute by frequency, 1 present = 1 point. 5 files that have highest score will be displayed
};

//For each KEY/QUERY, creat a vector of potential displayed items then choose 5 highest score files to display
//vector<displayedItem> display;

//Retrieval process: find out files that contains the found KEY/QUERY
void retrieval(string key, vector<displayedItem> &display, bool check, bool exact);

//Return pointer to new trieNode
trieNode* newNode();

//Insert a word to trie
void insert(trieNode *&root, string key);

//Search for a key, return TRUE if 'key' in the trie else return FALSE
bool search(trieNode* root, string key);

//compare score to sort the display vector
bool scoreCompare(const displayedItem &item1, const displayedItem &item2);

//highlight keyword with bright color then convert to the normal color
void makeColor(int colorCode);

//cout a sentence with keyword highlighted
void highLight(string sentence, string keyword);
void highLightTitleAND(string sentence, string key1, string key2);
void highLightAND(string sentence, string key1, string key2);
void highLightTitleOR(string sentence, string key1, string key2);
void highLightOR(string sentence, string key1, string key2);

//check if the word is in title
bool intitle(string& key);

//check the exact word
bool checkexact(string& key);

//Search with AND
void generateKey(string searchkey, string &key1, string &key2);
void searchWithAND(string key1, string key2, vector<displayedItem> &display);
void generateKeyOR(string searchkey, string &key1, string &key2);
void searchWithOR(string key1, string key2, vector<displayedItem> &display);




//search range
bool isRange(string key, double &low, double &high);

//search minus
bool HasMinus(string query, int &i);
string Removeminus(string query, int i);

//search +and
//bool HasPlus(string query, int &i);
//string firstplus(string query, int i);
//string lastplus(string query, int i);

//Full search
void Fullsearch(trieNode *&root, string query);
void Outputscreen(string query, bool search, bool check, bool exact);

//input files
void DataTree(trieNode *&root, ifstream &fin);
void SentenceTree(trieNode *&root, string sen);
void InputData(trieNode *&root);
string IntToString(int x);
string CreateFileName(int i, int j);

//stopwords
void InputStopwords(vector<string> stopwords);
bool isStopwords(string query, vector<string> stopwords);
//vector<string> getWords(string str, vector<string> stopwords);
//string RemoveStopwords(string query, vector<string> stopwords);

//history
void History(string query);
void OutputHistory(string query);
void clearHistory();

#endif