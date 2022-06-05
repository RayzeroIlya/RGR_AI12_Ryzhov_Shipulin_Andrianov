#include "vijglobal.h"
#include "isReg.h"

string decrypt(string key, string wordfodec) {
	if (key.size() < wordfodec.size()) {
		for (int i = key.size(), k = 0;i < wordfodec.size();i++, k++) {
			key = key + key[k];
		}
	}
	string DecWord;
	int IndexKey = 0;
	int IndexSymb = 0;
	vector<char> ActiveTable;
	for (int i = 0; i < key.size();i++) {
		if (wordfodec[i] == ' ') {
			DecWord += wordfodec[i];
			i++;
		}
		if (isReg(wordfodec[i]) == true) {
			ActiveTable = CaseEng;
		}
		else ActiveTable = CaseEngLow;
		for (int n = 0;n < ActiveTable.size();n++) {
			if (ActiveTable[n] == key[i]) {
				IndexKey = n;
				break;
			}
		}
		for (int n = 0;n < ActiveTable.size();n++) {
			if (ActiveTable[n] == wordfodec[i]) {
				IndexSymb = n;
				break;
			}if (wordfodec[i] == ' ') {
				i++;
				DecWord += ' ';
			}
		}
		if (ActiveTable == CaseEng) {
			vector<char> encr = TableEng[0];
			DecWord += encr[IndexSymb];
		}
		else {
			vector<char> encr = TableEngLow[0];
			DecWord += encr[IndexSymb];
		}
	}
	return DecWord;
}