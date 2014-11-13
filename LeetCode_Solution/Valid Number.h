#include <sstream>
#include <cstring>
#include <cstdio>
using namespace std;
class Solution {
public:
	bool isNumber(const char *s) {
		//string str(s);
		//stringstream buf(s);
		double num;
		char bak[1024];
		sscanf(s, "%lf%s", &num, bak);
		int len = strlen(bak);
		if (len == 0) return true;
		for (int i = 0; i < len; i++){
			if (bak[i] != ' '&&bak[i] != '\t') return false;
		}
		return true;
	}
};