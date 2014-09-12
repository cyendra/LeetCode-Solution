#include "std.h"

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		ans.resize(numRows);
		for (int i = 0; i < numRows; i++) ans[i].resize(i + 1);
		if (numRows == 0) return ans;
		ans[0][0] = 1;
		for (int i = 1; i < numRows; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0) ans[i][j] = ans[i - 1][j];
				else if (j == i) ans[i][j] = ans[i - 1][j - 1];
				else ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
			}
		}
		return ans;
	}
};