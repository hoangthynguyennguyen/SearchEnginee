//Final Project: Mini Search Engine
//Course: CS163_17CTT
//Group: 14

#include "function.h"

void normalizeString(string &key) {
	int bot = key.size();
	string nKey;
	//cout<<bot<<endl;
	for (int i = 0; i<bot; i++) {
		if (((key[i] >= 'a') && (key[i] <= 'z')) || (key[i] == '$') || (key[i] == 39) || ((key[i] == '-') && (key[i - 1] == ' '))) {
			nKey += key[i];
		}
		else if ((key[i] >= 'A') && (key[i] <= 'Z')) {
			nKey += key[i] + ('z' - 'Z');
		}
		else if ((key[i] >= '0') && (key[i] <= '9')) {
			nKey += key[i];
		}
		else if ((key[i] == ' ') && (i != 0) && (key[i - 1] != ' ')) {
			nKey += key[i];
		}
		else if ((key[i] == '-') || (key[i] == '/')) {
			nKey += ' ';
		}
	}
	key = nKey;
}