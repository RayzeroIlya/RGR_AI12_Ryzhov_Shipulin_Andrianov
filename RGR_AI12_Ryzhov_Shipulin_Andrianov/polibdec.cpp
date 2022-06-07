#include "bibliotec.h"
    struct info {
        string letter;
        int number = 0;
    };
    vector <info> alphabet = { { "À", 11}, {"Á", 12} ,{"Â",13},{"Ã",14}, {"Ä",15}, {"Å",16},
                        {"Æ",21},{"Ç",22}, {"È",23}, {"Ê",24}, {"Ë",25}, {"Ì",26},
                        {"Í",31}, {"Î",32}, {"Ï",33}, {"Ð",34}, {"Ñ",35}, {"Ò",36} ,
                        {"Ó",41}, {"Ô",42}, {"Õ",43}, {"Ö",44}, {"×",45}, {"Ø",46},
                        {"Ù",51}, {"Ú",52}, {"Û",53}, {"Ü",54}, {"Ý",55}, {"Þ",56},
                        {"ß",61}, {".",62}, {",",63}, {"?",64}, {";",65}, {":",66} };


   string polibdec(vector<int> nums) {
        
            int i;
            string text;
            for (int k = 0; k < nums.size(); k++) {
                for (i = 0; i < 36; i++) {
                    if (nums[k] == alphabet[i].number) {
                        text += alphabet[i].letter;
                        
                        i = 0; 
                        break;
                        
                    }
                }
            }
            cout << endl;  
        return text;
    }