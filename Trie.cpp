//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#include "Trie.h"

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