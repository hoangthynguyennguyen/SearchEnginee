#include "Trie.h"

//ALREADY BUILD

void outputonfile(char* path, string key, vector<string> tit);

void outputonfile(char* path, string key,vector<string> tit)
{

	ofstream fout;
	fout.open(path, ostream::app); //continue writing, if you want to overwrite, just delete ostream::app
	if (!fout.is_open())
	{
		cout << "Can not" << "\n";
		fout.close();
	}
	fout << endl;
	fout << "Search key: ";
	fout << key << "\n";
	for (int i = 0; i < tit.size(); i++)
	{
		fout << tit[i] << "\n";
		//STILL A LOOP TO FOUT CONTENT HERE
	}
	fout.close();
}