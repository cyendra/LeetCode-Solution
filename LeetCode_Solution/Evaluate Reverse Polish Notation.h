#include "std.h"

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		int n = tokens.size();
		stack<int> stk;
		for (int i = 0; i < n; i++)
		{
			if (tokens[i] == "+")
			{
				int a = stk.top(); stk.pop();
				int b = stk.top(); stk.pop();
				stk.push(a + b);
			}
			else if (tokens[i] == "-")
			{
				int a = stk.top(); stk.pop();
				int b = stk.top(); stk.pop();
				stk.push(b - a);
			}
			else if (tokens[i] == "*")
			{
				int a = stk.top(); stk.pop();
				int b = stk.top(); stk.pop();
				stk.push(a*b);
			}
			else if (tokens[i] == "/")
			{
				int a = stk.top(); stk.pop();
				int b = stk.top(); stk.pop();
				stk.push(b / a);
			}
			else
			{
				stringstream stm;
				stm << tokens[i];
				int a;
				stm >> a;
				stk.push(a);
			}
		}
		return stk.top();
	}
};