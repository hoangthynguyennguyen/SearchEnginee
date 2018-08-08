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
#include <chrono>
#include <iomanip>
#include <Windows.h>



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
void retrieval(string key, vector<displayedItem> &display);

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
//AnhThu
void DataTree(trieNode *&root, ifstream &fin);
void SentenceTree(trieNode *&root, string sen);


void InputData(trieNode *&root);
string IntToString(int x);
string CreateFileName(int i, int j);

















































/*

class Trie {
private:
	Trie();
	trieNode * root;
	trieNode * newNode();
	int charToIndex(char c);
public:
	void push(const char *key, string fileName);
	bool searchKey(const char *key);
	vector <string> searchFile(const char *key);
};*/
#endif