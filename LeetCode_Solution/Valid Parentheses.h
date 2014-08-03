#include "std.h"

class Solution {
public:
	bool isValid(string s) {
		int len = s.length();
		stack<char> stk;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(') stk.push(s[i]);
			if (s[i] == '[') stk.push(s[i]);
			if (s[i] == '{') stk.push(s[i]);
			if (s[i] == ')')
			{ 
				if (stk.empty()) return false;
				char c = stk.top();
				stk.pop();
				if (c != '(') return false;
			}
			if (s[i] == ']')
			{
				if (stk.empty()) return false;
				char c = stk.top();
				stk.pop();
				if (c != '[') return false;
			}
			if (s[i] == '}')
			{
				if (stk.empty()) return false;
				char c = stk.top();
				stk.pop();
				if (c != '{') return false;
			}
		}
		return stk.empty();
	}
};