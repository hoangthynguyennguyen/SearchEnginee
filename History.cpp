#include "Trie.h"

void History(string query)
{
	string q;
	q.append(query);
	transform(q.begin(), q.end(), q.begin(), ::tolower);

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
		if (q == tmp) exist = true;
		if (tmp.find(q) != string::npos)
		{
			i++;
			cout << i << ". " << tmp << endl;
		}
	}
	fin.close();

	if (i == 0)
		cout << "No history is found." << endl;

	if (exist) return; //if the query has existed in history, we don't need to write it down

	ofstream fout;
	fout.open("History.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "Can't open history" << endl;
		return;
	}
	fout << q << endl;
	fout.close();
}

void OutputHistory(string query)
{
	string q;
	q.append(query);
	transform(q.begin(), q.end(), q.begin(), ::tolower);
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
		if (q == tmp) exist = true;
	}
	fin.close();

	if (exist) return; //if the query has existed in history, we don't need to write it down

	ofstream fout;
	fout.open("History.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "Can't open history" << endl;
		return;
	}
	fout << q << endl;
	fout.close();
}

void clearHistory()
{
	ifstream fin;
	fin.open("history.txt", ios::out | ios::trunc);
	fin.close();
}