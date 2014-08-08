#include "std.h"

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.length();
		int m = word2.length(); 
		if (n == 0) return m;
		if (m == 0) return n;
		int INF = 0x3f3f3f3f;
		vector<vector<int> >f;
		f.resize(n+1);
		for (int i = 0; i <= n; i++)
		{
			f[i].resize(m + 1);
			for (int j = 0; j <= m; j++)
			{
				f[i][j] = INF;
			}
		}
		f[0][0] = 0;
		for (int i = 1; i <= n; i++) f[i][0] = i;
		for (int i = 1; i <= m; i++) f[0][i] = i;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (word1[i - 1] == word2[j - 1]) f[i][j] = f[i - 1][j - 1];
				else f[i][j] = f[i - 1][j - 1] + 1;
				f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1]) + 1);
			}
		}
		return f[n][m];
	}
};