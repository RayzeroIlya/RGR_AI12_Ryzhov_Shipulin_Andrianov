
int main()

{

	setlocale(LC_ALL, "russian");

	system("chcp 1251");

	system("cls");

	{

		char* string = new char[36];

		const int m = 6;

		const int n = 6;

		int i, j;

		cout << "������������, ��� ���� �������� �������" << endl;

		char A[m][n] = { {'�', '�', '�', '�', '�', '�' },

		{'�', '�', '�', '�', '�', '�' },

		{'�', '�', '�', '�', '�', '�' },

		{'�', '�', '�', '�', '�', '�' },

		{'�', '�', '�', '�','�', '�' },

		{'�', '.', ',', '?', ';', ':' } };

		for (int i = 0; i < m; i++)

		{

			for (int j = 0; j < n; j++)

			{

				cout << setw(2) << A[i][j] << ' ';

			}

			cout << endl;

		}

		cout << "������� ����� : ";

		cin >> string;

		for (int k = 0; k < strlen(string); k++)

		{

			for (i = 0; i < m; i++)

			{

				for (j = 0; j < n; j++)

				{

					if (string[k] == A[i][j])

					{

						cout << i + 1 << j + 1 << setw(2);

					}

				}

			}

		}

		cout << endl;

	}

	system("pause");

	return 0;

	+
}