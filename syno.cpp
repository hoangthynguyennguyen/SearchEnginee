#include "syno.h"
void syno::saveSynonym(string key)
{
	ifstream fin("synonyms.txt");
	if (!fin)
	{
		cout << "Can not open file " << endl;
	}
	int count = 0;
	vector<string> tokens;
	string line;
	while (getline(fin, line))
	{
		count++; // count line number
		istringstream is(line);
		string word;
		while (is >> word)
		{
			tokens.push_back(word);
			pos.insert(pair<string, int>(word, count)); // map use to store the position of each word(line number)

		}
		group.push_back(tokens);// vector 2D: store all position of words
	}
	fin.close();
}
vector<string> syno::getSyno(string key)
{
	map<string, int>::iterator it = pos.find(key);
	vector <string> word;
	if (pos.find(key) == pos.end()) // if key not found
	{
		return vector<string>(1, key);
	}
	else
	{

		int id = pos.begin()->second;
		word = group.at(id);
	}
	return word;
}