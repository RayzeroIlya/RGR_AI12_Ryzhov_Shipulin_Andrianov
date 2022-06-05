#include "vijglobal.h"

bool isReg(char symbol) {
	for (int i = 0;i < CaseEng.size();i++) {
		if (symbol == CaseEng[i]) return true;
	}
	for (int i = 0;i < CaseEngLow.size();i++) {
		if (symbol == CaseEngLow[i]) return false;
	}
}