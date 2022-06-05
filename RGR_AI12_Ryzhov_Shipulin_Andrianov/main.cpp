#include "vijglobal.h"
#include "vijfunc.h"

vector<char>CaseEng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
vector<char>CaseEngLow = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
map<int, vector<char>> TableEng;
map<int, vector<char>> TableEngLow;

int main() {
	setlocale(LC_ALL, "ru");
	int exit = 1;
	while (exit == 1) {
		cout << "Введите текст для шифровки и дешифровки на английском языке: " << endl;
		string checklist;
		getline(cin, checklist);
		/*block for caesar
		*/
		/*
		block for polobiya
		*/
		/*block for vijiner*/
		cout << "\t" << "Шифр Вижинера" << "\n";
		cout << "Введите ключ для шифровки и деширофки алгоритмом Вижинера: ";
		string key;
		cin >> key;
		key = keycheck(key, checklist);
		Vijiner();
		string EncWord = encrypt(key, checklist);
		decrypt(key, EncWord);

	}
}

