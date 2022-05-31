
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int Vijiner();



int main()
{


	setlocale(LC_ALL, "Rus");
	Vijiner();
	
}

int Vijiner() {
    vector<char>Case = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};// и так понятно что это
    /*std:vector<char>Symbol = { ' ', '+','!','@','#','$','%','^','&','*','[',']',')','(','=','`',':',';','{','}','.',',','<','>','"','?','/','\'' }*///; // это тоже понятно
	map<int, vector<char>> Table;
	for (int KeyTable = 0; KeyTable < Case.size();KeyTable++) {
			char SymbolMove;
			Table[KeyTable] = Case;
			SymbolMove = Case[0];
			Case.erase(Case.begin());
			Case.push_back(SymbolMove);

		

	}
	return 0;
}

