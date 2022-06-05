
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

		cout << "Здравствуйте, это шифр квадрата Полибия" << endl;

		char A[m][n] = { {'А', 'Б', 'В', 'Г', 'Д', 'Е' },

		{'Ж', 'З', 'И', 'К', 'Л', 'М' },

		{'Н', 'О', 'П', 'Р', 'С', 'Т' },

		{'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш' },

		{'Щ', 'Ъ', 'Ы', 'Ь','Э', 'Ю' },

		{'Я', '.', ',', '?', ';', ':' } };

		for (int i = 0; i < m; i++)

		{

			for (int j = 0; j < n; j++)

			{

				cout << setw(2) << A[i][j] << ' ';

			}

			cout << endl;

		}

		cout << "Введите слово : ";

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