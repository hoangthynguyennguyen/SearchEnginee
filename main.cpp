//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#include "Trie.h"

int main() {
	string keys[50] = { /*"the", "a", "there",
		"answer", "any", "by","bye", "their",
		"320", "7#" , "32", "$400", "#throwback",*/
		//"what about a whole long sentence", "kim", "phuong"
	};
	string myStr = "what about a whole long sentence";
	ifstream fin("input.txt");
	while (fin.good()) {
		getline(fin, myStr, '\n');

		//split a string containing whitespace into a keys[] by singleWords 
		int i = 0;

		stringstream ss(myStr);
		string singleWord;
		while (ss >> singleWord) {
			keys[i++] = singleWord;
		}
	}
	int n = sizeof(keys) / sizeof(keys[0]);
	trieNode* root = newNode();

	//build our trie^^
	for (int i = 0; i < n; ++i) {
		insert(root, keys[i]);
	}

	//search for a key
	string searchKey;
	string continuee = "y";
	bool answer;
	while (continuee == "y") {
		cout << "Type the word you want to check: ";
		cin >> searchKey;
		answer = search(root, searchKey);
		if (answer)
			cout << "yep\n";
		else
			cout << "nope\n";
		cout << "\nDo you want to continue? (y/n)  ";
		cin >> continuee;
		cout << endl;
	}
	
	cin.get();
	cin.get();
	return 0;
}