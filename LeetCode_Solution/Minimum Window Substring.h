#include "std.h"

class Solution {
public:
	int a[256];
	int b[256];
	int cnt;
	string minWindow(string S, string T) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cnt = 0;
		int n = S.length();
		int m = T.length();
		for (int i = 0; i < m; i++)
		{
			b[(int)T[i]]++;
		}
		int l = 0;
		int ans = -1;
		int mn = 0x3f3f3f3f;
		for (int i = 0; i < n; i++)
		{
			int h = (int)S[i];
			a[h]++;
			if (a[h]<=b[h]) cnt++;
			int d = (int)S[l];
			while (a[d]>b[d])
			{
				a[d]--;
				l++;
				d = (int)S[l];
			}
			if (cnt == m)
			{
				if (i - l + 1 < mn)
				{
					mn = i - l + 1;
					ans = l;
				}
			}
		}
		if (ans == -1) return "";
		else
		{
			string res;
			for (int i = 0; i < mn; i++)
			{
				res.push_back(S[ans + i]);
			}
			return res;
		}
	}
};