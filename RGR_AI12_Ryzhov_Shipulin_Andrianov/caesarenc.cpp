#include "caesar.h"

char *caesar(char msg[80])
{
    setlocale(LC_ALL, "ru");
    int i = 0, k;
    char ABC[] = { 'A','B','C','D','E','F','G','H','I',
                'J','K','L','M','N','O','P','Q','R',
                'S','T','U','V','W','X','Y','Z'
                ,'_','.',',','0','1','2','3',
                '4','5','6','7','8','9' };
    //char msg[80];
    //cout << "¬ведите сообщение заглавными латинскими буквами, которое будет закодировано: " << endl;
    //cin.seekg(cin.eof());
    //cin.getline(msg, 80);
    cout << "\n¬ведите сдвиг:" << endl;
    cin >> k;
    cout << endl;
    char* begin = ABC;
    char* end = ABC + sizeof(ABC);
    for (; msg[i]; ++i)
    {
        char* ch = find(begin, end, msg[i]);
        if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(ABC));
    }

    return msg;
}
