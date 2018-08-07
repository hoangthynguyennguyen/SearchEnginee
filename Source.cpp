
#include "trie.h"
int main()
{
	vector<string> stopwords;
	string searchw= "apple -banana";
	vector<string> a;
	string key;
	a = getWords(searchw, stopwords);

// Search Plus
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i].at(0) != '-'){
			searchw = a[i];
			break;
		}
		
		
	}
	cout << searchw;
// Search Minus
	searchw = a[0]; // apple
	for (int i = 1; i < a.size(); i++) 
	{
		searchw = a[i]; // i =2 'banana'
		if (a[i].at(0) == '+') //i = 1 '+and'
		{
			
			key = a[i].substr(1); // 'and'	
		}
		
	}

	searchw = a[0] + key + searchw;
	cout << searchw;
	

// searchExact_match( trieNode *root,string key, vector<string> stopwords)
		vector<string> query;
		string searchw;
		vector<string> res;
		if (key[0] == '"')
		{
			key = key.substr(1, key.length() - 1);
		}
		query = getWords(key, stopwords);

	return 0;
	
}