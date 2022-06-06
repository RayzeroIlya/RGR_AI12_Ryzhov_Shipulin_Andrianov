#include "bibliotec.h"

int Decypher() {
    setlocale(LC_ALL, "russian");
    system("chcp 1251");
    system("cls");
    {   char* string = new char[36];
    const int m = 6;
    const int n = 6;
    int i, j;
    char A[m][n] = { { 'А', 'Б', 'В', 'Г', 'Д', 'Е'},
                    { 'Ж', 'З', 'И', 'К', 'Л', 'М'},
                    { 'Н', 'О', 'П', 'Р', 'С', 'Т'},
                    { 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш'},
                    { 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю'},
                    { 'Я', '.', ',', '?', ';', ':' } };

 
    
    cout << "Введите зашифрованное слово : ";
    vector<int> v;
    int n1;
    while (cin >> n1)
        v.push_back(n1); 
    for (auto p = v.begin(); p != v.end(); ++p)
        cout << *p << ' ';
    for (int k = 0; k < v.size(); k++) {
        for (int t = 0; t < v.size(); t++) {
            for (i = 1; i < m; ++i){
                for (j = 1; j < n; ++j){
                    if (v[k] == i)
                    {
                        cout << A[i][j] << setw(2);
                    }
                }
            }
        }
    }
    cout << endl;  }
    system("pause");
    return 0;
}