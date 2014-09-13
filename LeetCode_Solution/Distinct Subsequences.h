#include "std.h"

class Solution {
public:
	int numDistinct(string S, string T) {
		int n = S.size();
		int m = T.size();
		vector<vector<int>>f;
		f.resize(S.size());
		for (int i = 0; i < n; i++) f[i].resize(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (S[i] == T[j]) {
					f[i][j] = f[i - 1][j - 1];
				}
				else {
					f[i][j] = min(min(f[i - 1][j], f[i][j - 1]),f[i-1][j-1]) + 1;
				}
			}
		}
	}
};