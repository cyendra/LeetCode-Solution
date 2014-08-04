#include "std.h"

class Solution {
public:
	void reverseWords(string &s) {
		if (s == "") return;
		stringstream buf(s);
		stringstream out;
		vector<string> v;
		string str;
		while (buf >> str)
		{
			v.push_back(str);
		}
		for (vector<string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		{
			if (it != v.rbegin()) out << " ";
			out << (*it);
		}
		getline(out, s);
	}
};