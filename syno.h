#ifndef SYNO_H
#define SYNO_H
#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class syno
{
private:
	map<string, int>pos;
	vector < vector<string>> group;
public:
	void inputSynonym();
	vector<string> getSyno(string key);
};
#endif