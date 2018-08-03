#include "Trie.h"

int main() {
	trieNode *root = newNode();
	string searchkey;
	
	InputData(root);
	

	cout << "Input search key: ";
	cin >> searchkey;

	
	if (Searching(root, searchkey))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	system("pause");
	return 0;
}