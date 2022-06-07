#include "bibliotec.h"

vector<int> polibenc(char* string)

{
	vector<int> nums;
	{
		const int m = 6;
		const int n = 6;
		int i, j;
		cout << "Квадрат Полибия" << endl;
		char A[m][n] = { {'А', 'Б', 'В', 'Г', 'Д','Е' },
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

		for (int k = 0; k < strlen(string); k++)
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (string[k] == A[i][j])
					{
						/*cout << i + 1 << j + 1 << setw(2);*/
						nums.push_back(i + 1);
						nums.push_back(j + 1);
					}
				}
			}
		}
		cout << endl;
	}
	return nums;
}
