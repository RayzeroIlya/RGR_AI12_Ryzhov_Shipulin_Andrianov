
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int Vijiner();

map<int, vector<char>> TableEng;

int main(){
	


	setlocale(LC_ALL, "Rus");
	Vijiner();
	
}

int Vijiner() {
    vector<char>Case = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};// и так понятно что это
    /*std:vector<char>Symbol = { ' ', '+','!','@','#','$','%','^','&','*','[',']',')','(','=','`',':',';','{','}','.',',','<','>','"','?','/','\'' }*///; // это тоже понятно
	map<int, vector<char>> TableEng;
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
	cout << '\t' << '\t' << "Vijiner's Table for English" << '\n' << '\n';


	
	
	return 0;
}
void encrypt(string key) {



}
