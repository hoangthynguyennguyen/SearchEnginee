#include "buttonSearch.h"
#include "menu.h"
#include "Trie.h"
#include "syno.h"

buttonSearch::buttonSearch()
{
	system("cls");

	trieNode *root = newNode();
	string searchkey, key1, key2;
	string continuee = "y";
	bool first = true;
	int choice;
	syno loaddd;
	vector<string>stopwords;
	clock_t startSearch, endSearch, searchTime;

	cout << "Loading data...Please wait a moment..." << endl;

	//Kieu Phuong

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	auto start1 = std::chrono::high_resolution_clock::now(); //start counting trie-building time

	InputData(root);  //trie is being built

	auto end1 = std::chrono::high_resolution_clock::now(); //end counting trie-building time

	//synonym.inputSynonym();
	InputStopwords(stopwords);

	while (continuee == "y" || continuee == "Y") {
		cout << "Input search key: ";
		if (!first)
		{
			cin.ignore();
		}
		getline(cin, searchkey, '\n');//--------------UPDATED
		first = false;
		//searchkey = std::string(searchkeyArr);
		//cout << "CHECKING " << searchkey << endl;
		//cout << "My searchkey: " << searchkey << endl;

		mem:
			cout << "Menu: " << endl;
			cout << "1. Search" << endl;
			cout << "2. Suggest history" << endl;
			cout << "3. Clear history" << endl;
			cout << "Your choice: ";
			cin >> choice;
			if (choice == 1)
			{
					startSearch = clock();
					//double a, b;
					//bool range = isRange(searchkey, a, b);
					//if(range)
					/*int j = 0;
					if (HasPlus(searchkey,j))
					{
					string first = firstplus(searchkey, j - 4);
					Fullsearch(root, first);

					string last = lastplus(searchkey, j);
					Fullsearch(root, last);

					goto Jump;
					}*/
					if (searchkey.find("and") != -1) {
						generateKey(searchkey, key1, key2);
						//searchWithAND;

						startSearch = clock();
						if (!search(root, key1) || !search(root, key2)) { //switch yes & no statement
							makeColor(10);
							cout << endl << "KEYWORD DOES NOT EXIT!" << endl << endl;
							makeColor(7);
						}
						if (search(root, key1) && search(root, key2)) {
							makeColor(10);
							cout << endl << "SEARCH RESULT(S):" << endl << endl;
							makeColor(7);
							//Display function goes here
							//For each KEY/QUERY, creat a vector of potential displayed items then choose 5 highest score files to display
							vector<displayedItem> displayAND;
							searchWithAND(key1, key2, displayAND);
						}
						goto Jump;
					}

					if (searchkey.find("or") != -1) {
						generateKeyOR(searchkey, key1, key2);


						startSearch = clock();
						if (!search(root, key1) || !search(root, key2)) { //switch yes & no statement
							makeColor(10);
							cout << endl << "KEYWORD DOES NOT EXIT!" << endl << endl;
							makeColor(7);
						}
						if (search(root, key1) && search(root, key2)) {
							makeColor(10);
							cout << endl << "SEARCH RESULT(S):" << endl << endl;
							makeColor(7);
							//Display function goes here
							//For each KEY/QUERY, creat a vector of potential displayed items then choose 5 highest score files to display
							vector<displayedItem> displayOR;
							searchWithOR(key1, key2, displayOR);
						}
						goto Jump;
					}

					if (searchkey[0] == '~') {
						searchkey = searchkey.substr(searchkey.find("~") + 1); //cut ~
						vector<string> stringsyn = loaddd.getSyno(searchkey);
						for (int i = 0; i < stringsyn.size(); i++)
						{

							searchkey = stringsyn[i];
							Fullsearch(root, searchkey);
						}
						goto Jump;
					}

					int i = 0;
					if (HasMinus(searchkey, i)) {
						searchkey = Removeminus(searchkey, i);//because i is point to ' ', we only need the word so i-1
					}
					Fullsearch(root, searchkey);

				Jump:;
					endSearch = clock();
					searchTime = endSearch - startSearch;
					makeColor(13);
					cout << "Searching time: " << (float)searchTime / CLOCKS_PER_SEC * 1000 << "ms" << endl;
					makeColor(7);
					OutputHistory(searchkey); //this word has been search
					cout << "\nDo you want to continue? (y/n)  ";
					cin >> continuee;
					cout << endl;
				}
			if (choice == 2)
			{
				cout << endl << "History: " << endl;
				History(searchkey);
				cout << endl;
				goto mem;
			}

			if (choice == 3)
			{
				clearHistory();
				cout << endl << "History has been cleared." << endl << endl;
				goto mem;
			}
		}

	
	//Kieu Phuong

	std::chrono::duration<double> diff1 = end1 - start1; //double, duration
	makeColor(13);
	cout << "Trie-building time: " << chrono::duration <double, milli>(diff1).count() << "ms" << endl;

	cin.get();


}
buttonSearch::~buttonSearch() {}