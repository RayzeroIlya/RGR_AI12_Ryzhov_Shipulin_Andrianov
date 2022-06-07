#include "vijfunc.h"




bool alphacheck(int shifr,char symbol) {

	vector<char> CaseRusP = { 'À','Á','Â','Ã','Ä','Å','Æ','Ç','È','Ê','Ë','Ì','Í','Î','Ï','Ð','Ñ','Ò','Ó','Ô','Õ','Ö','×','Ø','Ù','Ú','Û','Ü','Ý','Þ','ß','.',',','?',';',';' };
	vector<char> CaseEngC = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_','.',',','0','1','2','3','4','5','6','7','8','9' };
	int k = 0;
	switch (shifr)
	{
	case(1): {
		for (int n : CaseEngC) {
			if (symbol == n) {
				k = 1;
				break;
			}
		}
		if (k == 1)return true;
		else return false;
	}
	case(2): {
		for (int n : CaseRusP) {
			if (symbol == n) {
				k = 1;
				break;
			}
		}
		if (k == 1) return true;
		else return false;

	}
	case(3): {
		for (int n : CaseEng) {
			if (symbol == n) {
				k = 1;
				break;
			}
		}
		for (int n : CaseEngLow) {
			if (symbol == n) {
				k = 1;
				break;
			}
		}
		if (k == 1) return true;
		else return false;

	}
		default:
		break;
	}











}