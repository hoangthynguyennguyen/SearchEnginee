#include "Trie.h"

void InputStopwords(vector<string> stopwords)
{
	ifstream fin;
	fin.open("Stopwords_List.txt");
	if (!fin.is_open())
	{
		cout << "Can not open file" << endl;
		return;
	}
	string str;
	while (getline(fin, str))
	{
		if (str.size() > 0)
			stopwords.push_back(str);
	}
	cout << "Stopwords List.txt" << endl;
	fin.close();
}

bool isStopwords(string query, vector<string> stopwords){
	for (vector<string>::iterator i = stopwords.begin(); i != stopwords.end(); ++i)
	{
		if (query == *i)
			return true;
	}
	return false;
}

/*vector<string> getWords(string str, vector<string> stopwords)
{
vector<string> tokens;
string token;
istringstream is(str);
while (is >> token)
if (!isStopwords(token, stopwords))
tokens.push_back(token);
return tokens;
}

string RemoveStopwords(string query, vector<string> stopwords)
{
string keys;
vector<string> tmp;
tmp = getWords(query, stopwords);
keys = tmp[0];
for (int i = 1; i < tmp.size(); i++)
keys += (" " + tmp[i]);
keys.erase(keys.begin());
return keys;
}*/