#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


void caesar()
{
    setlocale(LC_ALL, "ru");
    int i = 0, k;
    char ABC[] = { '�','�','�','�','�','�','�','�','�',
                '�','�','�','�','�','�','�','�','�',
                '�','�','�','�','�','�','�','�','�',
                '�','�','�','�','�',
                '�','�','�','�','�','�','�','�','�',
                '�','�','�','�','�','�','�','�','�',
                '�','�','�','�','�','�','�','�','�',
                '�','�','�','�','�','_','.',',','0',
                '1','2','3','4','5','6','7','8','9' };
    char msg[80];
    cout << "������� ���������, ������� ����� ������������: " << endl;
    cin.seekg(cin.eof());
    cin.getline(msg, 80);
    cout << "\n������� �����:" << endl;
    cin >> k;
    cout << endl;
    char* begin = ABC;
    char* end = ABC + sizeof(ABC);
    for (; msg[i]; ++i)
    {
        char* ch = find(begin, end, msg[i]);
        if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(ABC));
    }
    cout << "���������� �������������� ���������: " << endl;
    cout << msg << endl;
}
