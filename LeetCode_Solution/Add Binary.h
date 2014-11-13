#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string c;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int lena = a.length();
		int lenb = b.length();
		int len = std::max(lena, lenb);
		int d = 0;
		for (int i = 0; i < len; i++) {
			if (i < lena) d += a[i] - '0';
			if (i < lenb) d += b[i] - '0';
			if (d >= 2) {
				c.push_back(d % 2 + '0');
				d /= 2;
			}
			else {
				c.push_back(d + '0');
				d = 0;
			}
		}
		if (d > 0) c.push_back(d + '0');
		reverse(c.begin(), c.end());
		return c;
	}
};