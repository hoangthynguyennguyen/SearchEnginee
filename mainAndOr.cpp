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

	

	//build our trie^^
	trieNode* root = newNode();
	for (int i = 0; i < n; ++i) {
		insert(root, keys[i]);
	}

	//search for a key
	string searchKey, key1, key2;
	string continuee = "y";
	bool answer;
	int answerNumber;
	cout << "You want to:" << endl
		<< "[1]Search a word" << endl
		<< "[2]Search with AND" << endl
		<< "[3]Search with OR" << endl
		<< "Pls type the number of your choice: ";
	cin >> answerNumber;
	switch (answerNumber) {
	case 1:
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
		break;
	case 2:  //need to process query to eliminate whitespace and "AND", only keep key1 and key2
		cout << "Pls input key1 and key2 respectively: ";
		cin >> key1 >> key2;
		if (search(root, key1) && search(root, key2)) {
			cout << "FOUND"; //if key1 AND key2 are both in the trie
		}
		else
			cout << "NOT_FOUND"; //if key1 or key2 is not in the trie
		break;
	case 3:  //need to process query to eliminate whitespace and "OR", only keep key1 and key2
		cout << "Pls input key1 and key2 respectively: ";
		cin >> key1 >> key2;
		if (search(root, key1) || search(root, key2)) {
			cout << "FOUND"; //if key1 OR key2 is in the trie
		}
		else
			cout << "NOT_FOUND";  //if neither of key1 nor key2 is in the trie
		break;
	}
	/*while (continuee == "y") {
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
	}*/
	
	cin.get();
	cin.get();
	return 0;
}