//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#ifndef TRIE_H
#define TRIE_H


#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

const int refSize = 42; //reference size = 42

struct trieNode {
	//string data;
	//int id;
	trieNode *next[refSize]; //0-9: '0' - '9'; 10-35: 'a' - 'z'; 36: whiteSpace; 37: '.' dot; 38: '$'; 39: '%'; 40: '#'; 41: '-'
	bool isLeaf = true;
	//vector <string> files;
};

//Return pointer to new trieNode
trieNode* newNode();

//Insert a word to trie
void insert(trieNode* root, string key);

//Search for a key, return TRUE if 'key' in the trie else return FALSE
bool search(trieNode* root, string key);

























































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