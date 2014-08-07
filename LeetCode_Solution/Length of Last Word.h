#include "std.h"

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		stringstream stm;
		stm << s;
		string out;
		int ans = 0;
		while (stm >> out)
		{
			ans = out.size();
		}
		return ans;
	}
};