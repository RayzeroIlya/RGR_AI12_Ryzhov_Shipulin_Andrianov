
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int Vijiner();
void encrypt(string key, string wordfoenc);
map<int, vector<char>> TableEng;
vector<char>Case = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

int main(){

	Vijiner();
	encrypt("LOX", "GAYLORD");
	setlocale(LC_ALL, "Rus");

	
}

int Vijiner() {
	cout << '\t' << '\t' << "Vijiner's Table for English" << '\n' << '\n';
	for (int KeyTable = 0; KeyTable < Case.size();KeyTable++) {
			char SymbolMove;
			TableEng[KeyTable] = Case;
			SymbolMove = Case[0];
			cout << KeyTable;
			for (int k = 0; k < Case.size();k++) {
				cout << Case[k];
			}
			cout << '\n';
			Case.erase(Case.begin());
			Case.push_back(SymbolMove);

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
	for (int i = 0; i < key.size();i++) {
		for (int n = 0;n < Case.size();n++) {
			if (Case[n] == key[i]) {
				IndexKey = n;
				break;
			}
		}
		for (int n = 0;n < Case.size();n++) {
			if (Case[n] == wordfoenc[i]) {
				IndexSymb = n;
				break;
			}
		}

		vector<char> encr = TableEng[IndexKey];
		EncWord += encr[IndexSymb];
	}
	cout << '\t' << EncWord << '\n';
}
