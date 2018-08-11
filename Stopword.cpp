#include "trie.h"
bool isStopwords(string query, vector<string> stopwords)
{
	ifstream in("C:\\cs163\\stopword.txt");
	if (!in)
	{
		cout << "Can not open file" << endl;
		return false;
	}
	string str;
	while (getline(in, str))
	{
		if (str.size() > 0)
			stopwords.push_back(str);
	}

	in.close();

	for (vector<string>::iterator i = stopwords.begin(); i != stopwords.end(); ++i)
	{
		if (query == *i)
			return true;
	}
	return false;

}
vector<string> getWords(string str, vector<string> stopwords)
{

	//int begin = 0;
	//int i;
	//string token;
	//vector<string> tokens;
	//int len = str.length();

	//for (i = 0; i < len; i++)
	//{
	//	if (str[i] == ' ')
	//	{
	//		int temp = i; // marked whitespace
	//		token = str.substr(begin, (temp - begin)); // cut string at where we marked back to starting point
	//		begin = temp + 1; 
	//		if (!isStopwords(token, stopwords))
	//		{
	//			tokens.push_back(token);
	//		}
	//	}
	//}
	//token = str.substr(begin, (i - begin)); // when i = length
	//if (!isStopwords(token, stopwords))
	//{
	//	tokens.push_back(token);
	//}

	//return tokens;
	vector<string> tokens;
	string token;
	istringstream is(str);
	while (is >> token)
	if (!isStopwords(token, stopwords))
		tokens.push_back(token);
	return tokens;

}