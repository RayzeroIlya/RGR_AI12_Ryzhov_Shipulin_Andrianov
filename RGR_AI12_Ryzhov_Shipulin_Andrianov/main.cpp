#include "vijglobal.h"
#include "vijfunc.h"
vector<char>CaseEng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
vector<char>CaseEngLow = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
map<int, vector<char>> TableEng;
map<int, vector<char>> TableEngLow;

int main() {
	
	setlocale(LC_ALL, "ru");
	cout << "������� ������ �������: " << endl;
	int password;
	cin >> password;
	while (password == 1111) {
		int choose;
		cout << "���� ������ :: 1" << endl;
		cout << "���� ������� :: 2" << endl;
		cout << "���� �������� :: 3" << endl;
		cout << "Close programm :: 0" << endl;
		cout << "��� �����: " << endl;
		cin >> choose;

		switch (choose)
		{
		case 0: {
			password = 0;
			break;
		}
		case 1: {cout << "=====================================================" << "\n";
			cout << "���� ������" << "\n";
			caesar();
			cout << "=====================================================" << "\n";
			break;
		}
		case 2: { cout << "=====================================================" << "\n";
			cout << "���� �������" << "\n";
			polib();
			cout << "=====================================================" << "\n";
			break;

		}
		case 3: {		cout << "=====================================================" << "\n";
			cout << "\t" << "���� ��������" << "\n";
			cout << "������� ����� ��� �������� � ���������� �� ���������� �����: " << endl;
			string text;
			cin.seekg(cin.eof());
			getline(cin, text);
			cout << "������� ���� ��� �������� � ���������� ���������� ��������: " << "\n";
			string key;
			cin >> key;
			key = keycheck(key, text);
			Vijiner();
			string EncWord = encrypt(key, text);
			decrypt(key, EncWord);
			cout << "=====================================================" << "\n";
			break;
		}
		default:
			cout << "������ �� �������." << "\n";
			cout << "���������� :: 1" << "\n";
			cout << "����� :: 0 " << "\n";
			cin >> password;
			if (password == 1) password = 1111;
			else
				password = 0;
			break;
		}

	}
}

