#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int chr[256];
		memset(chr, 0, sizeof(chr));
		int len = s.length();
		int ans = 0;
		int num = 0;
		int l = 0;
		for (int i = 0; i < len; i++)
		{
			int ch = (int)s[i];
			chr[ch]++;
			num++;
			while (chr[ch] > 1)
			{
				int id = (int)s[l++];
				chr[id]--;
				num--;
			}
			ans = max(ans, num);
		}
		return ans;
	}
};