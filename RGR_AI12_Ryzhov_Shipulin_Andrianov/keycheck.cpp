#include "vijglobal.h"



string keycheck(string key,string wordfoenc) {
	if (key.size() < wordfoenc.size()) {
		for (int i = key.size(), k = 0;i < wordfoenc.size();i++, k++) {
 key = key + key[k];
		}
	}
	return key;
}