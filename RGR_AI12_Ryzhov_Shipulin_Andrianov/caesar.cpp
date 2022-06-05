#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


void caesar()
{
    setlocale(LC_ALL, "ru");
    int i = 0, k;
    char ABC[] = { 'а','б','в','г','д','е','ж','з','и',
                'й','к','л','м','н','о','п','р','с',
                'т','у','ф','х','ц','ч','ш','щ','ъ',
                'ы','ь','э','ю','я',
                'А','Б','В','Г','Д','Е','Ж','З','И',
                'Й','К','Л','М','Н','О','П','Р','С',
                'Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ',
                'Ы','Ь','Э','Ю','Я','_','.',',','0',
                '1','2','3','4','5','6','7','8','9' };
    char msg[80];
    cout << "Введите сообщение, которое будет закодировано: " << endl;
    cin.seekg(cin.eof());
    cin.getline(msg, 80);
    cout << "\nВведите сдвиг:" << endl;
    cin >> k;
    cout << endl;
    char* begin = ABC;
    char* end = ABC + sizeof(ABC);
    for (; msg[i]; ++i)
    {
        char* ch = find(begin, end, msg[i]);
        if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(ABC));
    }
    cout << "Полученное закодированное сообщение: " << endl;
    cout << msg << endl;
}
