#include "vijglobal.h"
#include "vijfunc.h"
vector<char>CaseEng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
vector<char>CaseEngLow = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
map<int, vector<char>> TableEng;
map<int, vector<char>> TableEngLow;

int main() {
	
	setlocale(LC_ALL, "ru");
	cout << "Введите пароль доступа: " << endl;
	int password;
	cin >> password;
	while (password == 1111) {
		int choose;
		cout << "Шифр Цезаря :: 1" << endl;
		cout << "Шифр Полибия :: 2" << endl;
		cout << "Шифр Вижинера :: 3" << endl;
		cout << "Close programm :: 0" << endl;
		cout << "Ваш выбор: " << endl;
		cin >> choose;

		switch (choose)
		{
		case 0: {
			password = 0;
			break;
		}
		case 1: {cout << "=====================================================" << "\n";
			cout << "Шифр Цезаря" << "\n";
			caesar();
			cout << "=====================================================" << "\n";
			break;
		}
		case 2: { cout << "=====================================================" << "\n";
			cout << "Шифр Полибия" << "\n";
			polib();
			cout << "=====================================================" << "\n";
			break;

		}
		case 3: {		cout << "=====================================================" << "\n";
			cout << "\t" << "Шифр Вижинера" << "\n";
			cout << "Введите текст для шифровки и дешифровки на английском языке: " << endl;
			string text;
			cin.seekg(cin.eof());
			getline(cin, text);
			cout << "Введите ключ для шифровки и дешифровки алгоритмом Вижинера: " << "\n";
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
			cout << "Ничего не выбрано." << "\n";
			cout << "Перезапуск :: 1" << "\n";
			cout << "Выход :: 0 " << "\n";
			cin >> password;
			if (password == 1) password = 1111;
			else
				password = 0;
			break;
		}

	}
}

