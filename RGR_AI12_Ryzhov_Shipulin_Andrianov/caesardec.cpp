#include "caesar.h"

char *caesardec(char msg[80]) {
       cout << "¬ведите сдвиг: ";
       int k;
       cin >> k;
    for (int i = 0; i < strlen(msg); i++) {
        msg[i] -= k;
    }

        return msg;
}