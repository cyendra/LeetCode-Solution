#include "std.h"

class Solution {
public:
	vector<vector<int>> f;
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		if (n == 0) return 0;
		f.resize(n);
		for (int i = 0; i < n; i++) f[i].resize(i + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (i == 0) f[i][j] = triangle[i][j];
				else if (j == 0) f[i][j] = triangle[i][j] + f[i - 1][j];
				else if (j == i) f[i][j] = triangle[i][j] + f[i - 1][j - 1];
				else f[i][j] = triangle[i][j] + min(f[i - 1][j - 1], f[i - 1][j]);
			}
		}
		int ans = f[n - 1][0];
		for (int i = 1; i < n; i++) ans = min(ans, f[n - 1][i]);
		return ans;
	}
};