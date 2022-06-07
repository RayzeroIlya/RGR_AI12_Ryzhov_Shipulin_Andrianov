#include "vijglobal.h"
#include "vijfunc.h"
vector<char>CaseEng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
vector<char>CaseEngLow = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
map<int, vector<char>> TableEng;
map<int, vector<char>> TableEngLow;

int main() {	
	char* DecWordc = nullptr;
	char* EncWordc = nullptr;
	string EncWord;
	vector<int>EncWordP;
	system("chcp 1251");
	setlocale(LC_ALL, "ru");
	system("cls");
	cout << "Введите пароль доступа: ";
	int password;
	cin >> password;
	while (password == 1111) {
		cout << "Ввод с консоли :: 0" << endl << "Ввод с файла :: 1" << endl;
		cout << "Выберите способ ввода: ";
		int inchoose;
		cin >> inchoose;
		string text;
		switch (inchoose)
		{
		case (0): {

			int choose;
			cout << endl;
			cout << "Шифр Цезаря :: 1" << endl;
			cout << "Шифр Полибия :: 2" << endl;
			cout << "Шифр Вижинера :: 3" << endl;
			cout << "Close programm :: 0" << endl;
			cout << "Ваш выбор: ";
			cin >> choose;
			int ecdc;
			switch (choose)
			{
			case 0: {
				password = 0;
				break;
			}
			case (1): {
				cout << "=====================================================" << "\n";
				cout << "Шифр Цезаря" << "\n";
				cout << "Зашифровать :: 1" << endl << "Дешифровать :: 2" << endl;
				cout << "Ваш выбор: ";
				cin >> ecdc;
				switch (ecdc)
				{
				case(1): {
					cout << "Введите сообщение заглавными латинскими буквами, которое будет закодировано: " << endl;
					cin.seekg(cin.eof());
					char msg[80];
					cin.getline(msg, 80);
					

					EncWordc = caesar(msg);
					if (EncWordc[0] == '{') {
						cout << "Используется неверный алфавит!" << endl;
						break;
					}
					cout << "Полученное закодированное сообщение: " << endl;
					cout << EncWordc << endl;
					break;

				}
				case(2): {
					cout << "Ввести новое сообщение:: 1" << "\n" << "Использовать прошлое сообщение :: 2" << endl;
					cout << "Ваш выбор: ";
					int ecdc;
					cin >> ecdc;
					switch (ecdc)
					{
					case (1): {
						cout << "Введите сообщение заглавными латинскими буквами, которое будет раскодировано: " << endl;
						cin.seekg(cin.eof());
						char msg[80];
						cin.getline(msg, 80);
						DecWordc = caesardec(msg);
						if (DecWordc[0] == '{') {
							cout << "Используется неверный алфавит!" << endl;
							break;
						}
						cout << "\nРаскодированное сообщение:\n\n" << DecWordc << endl << endl;
						break;

					}
					case(2): {
						if (DecWordc == nullptr) {
							cout << "Сообщение пустое";
							break;
						}
						DecWordc = caesardec(EncWordc);
						cout << "\nРаскодированное сообщение:\n\n" << DecWordc << endl << endl;
						break;

					}
					default:
						break;
					}
				}
				default:
					break;
				}
				cout << "=====================================================" << "\n";
				system("pause");
				system("cls");
				break;
			} 
			case (2): {
				cout << "=====================================================" << "\n";
				cout << "Шифр Полибия" << "\n";
				cout << "Зашифровать :: 1" << endl << "Дешифровать :: 2" << endl;
				cout << "Ваш выбор: ";
				cin >> ecdc;
				char* textp = new char[36];
				switch (ecdc)
				{
				case(1): {
					cout << "Введите слово для шифровки русскими заглавными буквами: ";


					cin >> textp;
					for (int i = 0;i < strlen(textp);i++) {
						if (alphacheck(2, textp[i])) continue;
						else {
							textp[0] = '{';
						}
					}
						if (textp[0] == '{') {
							cout << "Используется неверный алфавит!" << endl;
							break;
						}
						EncWordP = polibenc(textp);
						for (int n : EncWordP) {
							cout << n;
						}
						break;
					}
				case(2): {
					cout << "Ввести новое сообщение:: 1" << "\n" << "Использовать прошлое сообщение :: 2" << endl;
					cout << "Ваш выбор: ";
					int ecdc;
					cin >> ecdc;
					switch (ecdc)
					{
					case(1): {
						cout << "Введите сообщение для дешифровки парами цифр(Введите либое НЕ число чтобы остановить ввод: ";
						vector<int> nums;
						int n1;
						while (cin >> n1) {
							if (n1 % 10 > 6 or n1 / 10 > 6) {
								cout << "Введите другое число: ";
								continue;
							}
							nums.push_back(n1);
						}
						string text = polibdec(nums);
						cout << "Дешифрованое сообщение: " << text;
						break;
					}
					case(2): {	
						vector<int> nums;
						for (int i = 0;i < EncWordP.size();i+=2) {
							stringstream stream;
							stream << EncWordP[i] << EncWordP[i + 1];
							int c;
							stream >> c;
							nums.push_back(c);
						}
						string text = polibdec(nums);
						cout << "Дешифрованное сообщение: "<< text;
						break;
					}
						default:
							break;
					}

				}
				default:
					break;
				}
				
					   cout <<"\n" << "=====================================================" << "\n";
					   system("pause");
					   system("cls");
					   break;
				}
			case (3): {
				cout << "=====================================================" << "\n";
				cout << "\t" << "Шифр Вижинера" << "\n";
				Vijiner();
				cout << "Зашифровать :: 1" << endl << "Дешифровать :: 2" << endl;
				cout << "Ваш выбор: ";
				cin >> ecdc;
				switch (ecdc)
				{
				case(1): {

					cout << "Введите текст для шифровки английском языке: ";
					cin.seekg(cin.eof());
					getline(cin, text);
					cout << "Введите ключ для шифровки алгоритмом Вижинера: ";
					string key;
					cin >> key;
					key = keycheck(key, text);
					EncWord = encrypt(key, text);
					if (EncWord[0] == '{') {
						cout << "Используется неверный алфавит!" << endl;
						break;
					}
					break;
				}
				case(2): {
					cout << "Ввести новый текст :: 1" << endl << "Использовать закодированный текст :: 2" << endl;
					cout << "Ваш выбор: ";
					cin >> ecdc;
					switch (ecdc)
					{
					case(1): { cout << "Введи текст для дешифровки: ";
						cin.seekg(cin.eof());
						getline(cin, text);
						cout << "Введи ключ для дешифровки: ";
						string key;
						cin >> key;
						key = keycheck(key, text);
						text = decrypt(key, text);
						if (text[0] == '{') {
							cout << "Используется неверный алфавит!" << endl;
							break;
						}
					}
					case(2): {
						cout << "Введи ключ для дешифровки: ";
						if (EncWord.size() == 0) {
							cout << "Нет закодированного текста" << endl;
							break;
						}
						string key;
						cin >> key;
						key = keycheck(key, EncWord);
						text = decrypt(key, EncWord);
						if (text[0] == '{') {
							cout << "Используется неверный алфавит!" << endl;
							cout << "Зашифруйте слово еще раз для использования!" << endl;
							break;
						}
					}
						   break;
					}
				default:
					break;
				}
				}
				cout << "=====================================================" << "\n";
				system("pause");
				system("cls");
				break;
			}
			default: {
				cout << "Ничего не выбрано." << "\n";
				cout << "Перезапуск :: 1" << "\n";
				cout << "Выход :: 0 " << "\n";
				cin >> password;
				if (password == 1) password = 1111;
				else
					password = 0;
				system("cls");
				break;
			}
			}
			break;
		}
		case (1): {
			cout << endl;
			cout << "Шифр Цезаря :: 1" << endl;
			cout << "Шифр Полибия :: 2" << endl;
			cout << "Шифр Вижинера :: 3" << endl;
			cout << "Close programm :: 0" << endl;
			cout << "Ваш выбор: ";
			int fchoose;
			int ecdc;
			cin >> fchoose;
			switch (fchoose)
			{
			case (1): {
				cout << "=====================================================" << "\n";
				cout << "Шифр Цезаря" << "\n";
				cout << "Зашифровать :: 1" << endl << "Дешифровать :: 2" << endl;
				cout << "Ваш выбор: ";
				cin >> ecdc;
				switch (ecdc)
				{
				case(1): {
				ifstream fin("caesartext.txt");
				char msg[80];
				fin.getline(msg,80);
				fin.close();
				EncWordc = caesar(msg);
				if (EncWordc[0] == '{') {
					cout << "Используется неверный алфавит!" << endl;
					break;
				}
				ofstream fout("caesarout.txt",ios_base::trunc);
				fout << EncWordc;
				fout.close();
					break;

				}
				case(2): {
					ifstream fin("caesarout.txt");
					char msg[80];
					fin.getline(msg, 80);
					fin.close();
					DecWordc = caesardec(msg);
					if (DecWordc[0] == '{') {
						cout << "Используется неверный алфавит!" << endl;
						break;
					}
					ofstream fout("caesarout.txt", ios_base::trunc);
					fout << DecWordc;
					fout.close();
					break;
				}
				default:
					break;
				}
				system("pause");
				system("cls");
				cout << "=====================================================" << "\n";




			}
			case (2): {
				cout << "=====================================================" << "\n";
				cout << "Шифр Полибия" << "\n";
				cout << "Зашифровать :: 1" << endl << "Дешифровать :: 2" << endl;
				cout << "Ваш выбор: ";
				cin >> ecdc;
				switch (ecdc)
				{
				case(1): {
					ifstream fin("polibtext.txt");
					char* textp = new char[36];
					fin.getline(textp,36);
					fin.close();
					for (int i = 0;i < strlen(textp);i++) {
						if (alphacheck(2, textp[i]));
						else {
							textp[0] = '{';
						}
						if (textp[0] == '{') {
							cout << "Используется неверный алфавит!" << endl;
							break;
						}
					}
						vector<int>EncWordP = polibenc(textp);
						ofstream fout("polibout.txt", ios_base::trunc);
						int t = 0;
						for (int n : EncWordP) {
							if (t == 0) {
								fout << n;
								t++;
							}
							else {
								fout << n << ' ';
								t--;
							}

						}
						fout.close();
						system("pause");
						system("cls");
						break;
					}
				case(2): {
					ifstream fin("polibout.txt");
					vector<int> nums;
					while (!fin.eof()) {
						int n;
						fin >> n;
						nums.push_back(n);
					}
					
					string text =polibdec(nums);
					text[text.size()-1] = ' ';
					ofstream fout("polibout.txt",ios_base::trunc);
					fout << text;
					fout.close();
					break;
				}
				default:
					break;
				}
				cout << "=====================================================" << "\n";
				system("cls");
				break;
			}
			case (3): {
				cout << "=====================================================" << "\n";
				cout << "\t" << "Шифр Вижинера" << "\n";
				Vijiner();
				cout << "Зашифровать :: 1" << endl << "Дешифровать :: 2" << endl;
				cout << "Ваш выбор: ";
				cin >> ecdc;
				switch (ecdc)
				{
				case(1): {
					ifstream fin("vijtext.txt");
					string fEncWord;
					string text;
					getline(fin, text);
					fin.close();
					cout << "Введите ключ для шифровки алгоритмом Вижинера: ";
					string key;
					cin >> key;
					key = keycheck(key, text);
					fEncWord = encrypt(key, text);
					if (fEncWord[0] == '{') {
						cout << "Используется неверный алфавит!" << endl;
						break;
					}
					ofstream fout("vijout.txt");
					fout << fEncWord;
					fout.close();
					break;
				}
				case(2): {
					ifstream fin("vijout.txt");
					string text;
					getline(fin, text);
					fin.close();
					if (text.size() == 0) break;
					cout << "Введите ключ для дешифровки алгоритмом Вижинера: ";
					string key;
					cin >> key;
					key = keycheck(key, text);
					string fDecWord = decrypt(key, text);
					if (fDecWord[0] == '{') {
						cout << "Используется неверный алфавит!" << endl;
						break;
					}
					ofstream fout("vijout.txt", ios_base::trunc);
					fout << fDecWord;
					fout.close();
					break;
				}
				default:
					break;
				}

				cout << "=====================================================" << "\n";
				system("pause");
				system("cls");
				break;
			}
			default: {
				cout << "Ничего не выбрано. p" << "\n";
				cout << "Перезапуск :: 1" << "\n";
				cout << "Выход :: 0 " << "\n";
				cin >> password;
				if (password == 1) password = 1111;
				else
					password = 0;
				system("cls");
				break;
			}
			}


			break;
		}
		default: {

		}
		}

	}
	}