//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#ifndef _TRIE_H_
#define _TRIE_H_

#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

struct trieNode {
	string data;
	int id;
	trieNode *next[42]; //0-9: '0' - '9'; 10-35: 'a' - 'z'; 36: whiteSpace; 37: '.' dot; 38: '$'; 39: '%'; 40: '#'; 41: '-'
	bool isLeaf = true;
	vector <string> files;
};

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
};
#endif