#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

/*
Drawbacks: 
- You have to normalize all of them
- Also if the query is space (or lots of space), it will show all results that contain space @@
*/

void SuggestHistory(vector<string>his, string query)
{
	his.push_back(query);
	ifstream fin;
	fin.open("History.txt");
	if (!fin.is_open())
	{
		cout << "Can't open history" << endl;
		return;
	}
	int i = 0;
	bool exist = false;
	while (!fin.eof())
	{
		string tmp;
		getline(fin, tmp, '\n');
		if (query == tmp) exist = true; 
		if (tmp.find(query) != string::npos)
		{
			i++;
			cout << i << ". " << tmp << endl;
		}
		his.push_back(tmp);
	}

	fin.close();

	if (i == 0)
		cout << "No history is found." << endl;

	if (exist) return; //if the query has existed in history, we don't need to rewrite it

	ofstream fout;
	fout.open("History.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "Can't open history" << endl;
		return;
	}
	fout << query << endl;
	fout.close();
}


int main()
{
	vector<string>his;
	string query;
	getline(cin, query);
	SuggestHistory(his, query);
	system("pause");
	return 0;
}

