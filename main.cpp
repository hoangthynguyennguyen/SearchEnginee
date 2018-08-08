//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#include "Trie.h"

int main() {
	//KP
	/*
	string keys[50] = { 
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

	*/

	
	

	//Anh Thu

	trieNode *root = newNode();
	string searchkey;
	string continuee = "y";
	clock_t startSearch, endSearch, searchTime;

	cout << "Loading data...Please wait a moment..." << endl;
	//Kieu Phuong
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	auto start1 = std::chrono::high_resolution_clock::now(); //start counting trie-building time

	InputData(root);  //trie is being built
	
	auto end1 = std::chrono::high_resolution_clock::now(); //end counting trie-building time

	while (continuee == "y") {
		cout << "Input search key: ";  //need a string query, not a key - getline instead of cin
		//getline(cin, searchkey, ' ');
		cin >> searchkey;
		startSearch = clock();
		if (!search(root, searchkey)) //switch yes & no statement
			cout << "No" << endl;
		else {
			cout << "Yes" << endl;
			//Display function goes here
			//For each KEY/QUERY, creat a vector of potential displayed items then choose 5 highest score files to display
			vector<displayedItem> display;
			retrieval(searchkey, display);
		}
		endSearch = clock();
		searchTime = endSearch - startSearch;
		makeColor(13);
		cout << "Searching time: " << (float)searchTime / CLOCKS_PER_SEC * 1000 << "ms" << endl;
		makeColor(7);
		cout << "\nDo you want to continue? (y/n)  ";
		cin >> continuee;
		cout << endl;
	}
	
	//Kieu Phuong
	
	std::chrono::duration<double> diff1 = end1 - start1; //double, duration
	makeColor(13);
	cout << "Preprocessing time: " << chrono::duration <double, milli>(diff1).count() << " ms" << endl;

	cin.get();
	cin.get();
	return 0;
}