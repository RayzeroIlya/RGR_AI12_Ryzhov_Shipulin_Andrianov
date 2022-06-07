#include "caesar.h"

char *caesardec(char msg[80]) {
    char ABC[] = { 'A','B','C','D','E','F','G','H','I',
            'J','K','L','M','N','O','P','Q','R',
            'S','T','U','V','W','X','Y','Z'
            ,'_','.',',','0','1','2','3',
            '4','5','6','7','8','9' };
    char* begin = ABC;
    char* end = ABC + sizeof(ABC);
       cout << "¬ведите сдвиг: ";
       int k;
       cin >> k;
       for (int i =0;msg[i];i++) {
           if (msg[i] == NULL) break;
           if (alphacheck(1, msg[i])) i = 0;
           else {
               if (msg[i] == ' ') continue;
               else {
                   msg[0] = '{';
                   return msg;
               }
           }
               for (int i = 0; i < strlen(msg); i++) {
                   msg[i] -= k;
               }
               break;
           }
        return msg;
}