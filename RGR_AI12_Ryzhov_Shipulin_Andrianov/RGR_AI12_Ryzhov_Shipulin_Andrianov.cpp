
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
bool isReg(char symbol);
int Vijiner();
void decrypt(string key,string word);
void encrypt(string key, string wordfoenc);


map<int, vector<char>> TableEng;
map<int, vector<char>> TableEngLow;
vector<char>CaseEng =    { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
vector<char>CaseEngLow = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int main(){
	string word, key;
	cout << "Input word: ";
	getline(cin, word);

	cout << "Input key: ";
	(cin >> key).get();
	cout << "\t" << word << "\n";
	Vijiner();
	encrypt(key, word);
	decrypt(key, word);
	setlocale(LC_ALL, "Rus");


		
	
}

int Vijiner() {
	cout << '\t' << '\t' << "Vijiner's Table for English Upper" << '\n' << '\n';
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
	cout << '\t' << '\t' << "Vijiner's Table for English Lower" << '\n' << '\n';
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

	
	
	return 0;
}
void encrypt(string key,string wordfoenc) {
	if (key.size() < wordfoenc.size()) {
		for (int i = key.size(), k = 0;i < wordfoenc.size();i++,k++) {
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
		} else ActiveTable = CaseEngLow;

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
	cout << '\t' << EncWord << '\n';
}


void decrypt(string key, string wordfodec) {
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
		if (isReg(wordfodec[i])==true) {
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
	cout << '\t' << DecWord << '\n';
}

bool isReg(char symbol) {
	for (int i = 0;i < CaseEng.size();i++) {
		if (symbol == CaseEng[i]) return true;
		else if (symbol == CaseEngLow[i]) return false;
	}
	}
