#include "vijglobal.h"
#include "isReg.h"
string encrypt(string key, string wordfoenc) {
	if (key.size() < wordfoenc.size()) {
		for (int i = key.size(), k = 0;i < wordfoenc.size();i++, k++) {
			key = key + key[k];
		}
	}
	string EncWord;
	int IndexKey = 0;
	int IndexSymb = 0;
	vector<char> ActiveTable;
	for (int i = 0, h = 0; i < key.size();i++, h++) {
		if (wordfoenc[i] == ' ') {
			EncWord += wordfoenc[i];
			i++;
		}
		if (isReg(wordfoenc[i]) == true) {
			ActiveTable = CaseEng;
		}
		else ActiveTable = CaseEngLow;

		for (int n = 0;n < ActiveTable.size();n++) {
			if (ActiveTable[n] == key[h]) {
				IndexKey = n;
				break;
			}
		}
		for (int n = 0;n < ActiveTable.size();n++) {
			if (ActiveTable[n] == wordfoenc[i]) {
				IndexSymb = n;
				break;
			}

		}
		vector<char> encr;
		if (ActiveTable == CaseEng) {
			vector<char> encr = TableEng[IndexKey];
			EncWord += encr[IndexSymb];
		}
		else {
			vector<char> encr = TableEngLow[IndexKey];
			EncWord += encr[IndexSymb];
		}
	}
	return EncWord;
}


