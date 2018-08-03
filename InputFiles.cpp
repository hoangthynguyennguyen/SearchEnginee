#include "Trie.h"

string IntToString(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

//string FloatToString(int x) {
//	stringstream ss;
//	ss << x;
//	return ss.str();
//}
//
//bool IsWord(char key)
//{
//	if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122)) return true;
//	return false;
//}

void InputData(trieNode *&root)
{
	ifstream fin;
	string FileName;
	//for (int i = 1; i <= 25; i++)
		for (int j = 1; j <= 25; j++)
		{
			FileName = CreateFileName(14, j); //go to CreateFileName function
			fin.open(FileName);
			if (!fin.is_open())
			{
				cout << "Can't open file " << FileName << endl; //can't open file
				continue;
			}
			cout << FileName << endl;
			DataTree(root, fin);
			fin.close();
		}
	//for (int i = 0; i <= 100; i++) //101 files, 2 loops could be merged later
	//{
	//	FileName = IntToString(i) + ".txt";
	//	fin.open(FileName);
	//	if (!fin.is_open())
	//	{
	//		cout << "Can't open file " << FileName << endl; //can't open file
	//		continue;
	//	}
	//	cout << FileName << endl;
	//	fin.close();
	//}
}

string CreateFileName(int i, int j)
{
	string GroupNumber = IntToString(i), TxtNumber = IntToString(j);
	if (1 <= i && i <= 9)
	{
		if (1 <= j && j <= 9)
			return ("Group0" + GroupNumber + "News0" + TxtNumber + ".txt"); //Group01News01.txt
		else
			return ("Group0" + GroupNumber + "News" + TxtNumber + ".txt"); //Group01News10.txt
	}
	else
	{
		if (1 <= j && j <= 9)
			return ("Group" + GroupNumber + "News0" + TxtNumber + ".txt"); //Group10News01.txt
		else
			return ("Group" + GroupNumber + "News" + TxtNumber + ".txt"); //Group10News10.txt
	}
}