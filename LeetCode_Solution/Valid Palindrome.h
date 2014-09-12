#include "std.h"

class Solution {
public:
	bool isPalindrome(string s) {
		string b;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			if (isalnum(s[i])) b.push_back(tolower(s[i]));
		}
		n = b.size();
		for (int i = 0; i < n / 2; i++) {
			int j = n - i - 1;
			if (b[i] != b[j]) return false;
		}
		return true;
	}
};