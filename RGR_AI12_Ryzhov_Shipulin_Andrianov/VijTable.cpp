#include "vijglobal.h"

void Vijiner() {
	cout << '\t' << '\t' << "Таблица Вижинера для букв верхнего регистра" << '\n' << '\n';
	for (int KeyTable = 0; KeyTable < CaseEng.size();KeyTable++) {
		char SymbolMove;
		TableEng[KeyTable] = CaseEng;
		SymbolMove = CaseEng[0];
		cout << KeyTable;
		for (int k = 0; k < CaseEng.size();k++) {
			cout << CaseEng[k];
		}
		cout << '\n';
		CaseEng.erase(CaseEng.begin());
		CaseEng.push_back(SymbolMove);

	}
	cout << '\t' << '\t' << "Таблица Вижинера для букв нижнего регистра" << '\n' << '\n';
	for (int KeyTable = 0; KeyTable < CaseEngLow.size();KeyTable++) {
		char SymbolMove;
		TableEngLow[KeyTable] = CaseEngLow;
		SymbolMove = CaseEngLow[0];
		cout << KeyTable;
		for (int k = 0; k < CaseEngLow.size();k++) {
			cout << CaseEngLow[k];
		}
		cout << '\n';
		CaseEngLow.erase(CaseEngLow.begin());
		CaseEngLow.push_back(SymbolMove);

	}
}