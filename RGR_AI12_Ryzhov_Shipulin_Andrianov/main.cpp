#include "vijglobal.h"
#include "vijfunc.h"
#include <conio.h>

vector<char>CaseEng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
vector<char>CaseEngLow = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
map<int, vector<char>> TableEng;
map<int, vector<char>> TableEngLow;

int main() {
	setlocale(LC_ALL, "ru");
	int exit = 1;
	while (exit == 1) {
		int choose;
		cout << "���� ������ :: 1" << endl;
		cout << "���� ������� :: 2" << endl;
		cout << "���� �������� :: 3" << endl;
		cout << "�������� �������� ����������: ";
		cin >> choose;

		switch (choose)
		{
		case 1: {

		}
		case 2: {

		}
		case 3: {		
			cout << "\t" << "���� ��������" << "\n";
			cout << "������� ����� ��� �������� � ���������� �� ���������� �����: " << endl;
			string text;
			getline(cin, text);
			cout << "������� ���� ��� �������� � ��������� ���������� ��������: " << "\n";
			string key;
			cin >> key;
			key = keycheck(key, text);
			Vijiner();
			string EncWord = encrypt(key, text);
			decrypt(key, EncWord);
		}
		default:
			cout << "BREAK";
			break;
		}

	}
}

