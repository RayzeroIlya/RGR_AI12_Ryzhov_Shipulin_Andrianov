#include "vijglobal.h"
#include "isReg.h"

string decrypt(string key, string wordfodec) {

	string DecWord;
	int IndexKey = 0;
	int IndexSymb = 0;
	for (int i = 0;i < wordfodec.size();i++) {
		if (alphacheck(3, wordfodec[i]) && alphacheck(3, key[i]));
		else {
			if (wordfodec[i] == ' ') i = i;
			else{
			wordfodec[0] = '{';
			return wordfodec;
			}
		}

	}
	vector<char> ActiveTable;
	for (int i = 0, h =0; i < key.size();i++,h++) {
		if (wordfodec[i] == ' ') {
			DecWord += wordfodec[i];
			i++;
		}
		if (isReg(wordfodec[i]) == true) {
			ActiveTable = CaseEng;
		}
		else ActiveTable = CaseEngLow;
		for (int n = 0;n < ActiveTable.size();n++) {
			if ((CaseEng[n] == key[h]) || (CaseEngLow[n] == key[h])) {
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
			DecWord += encr[(IndexSymb-IndexKey +26)%26];
		}
		else {
			vector<char> encr = TableEngLow[0];
			DecWord += encr[(IndexSymb-IndexKey + 26)%26];
		}
	}
	cout << "Дешифрованный текст: " << DecWord << endl;
	return DecWord;
}