#include "bibliotec.h"
    struct info {
        string letter;
        int number = 0;
    };
    vector <info> alphabet = { { "�", 11}, {"�", 12} ,{"�",13},{"�",14}, {"�",15}, {"�",16},
                        {"�",21},{"�",22}, {"�",23}, {"�",24}, {"�",25}, {"�",26},
                        {"�",31}, {"�",32}, {"�",33}, {"�",34}, {"�",35}, {"�",36} ,
                        {"�",41}, {"�",42}, {"�",43}, {"�",44}, {"�",45}, {"�",46},
                        {"�",51}, {"�",52}, {"�",53}, {"�",54}, {"�",55}, {"�",56},
                        {"�",61}, {".",62}, {",",63}, {"?",64}, {";",65}, {":",66} };


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