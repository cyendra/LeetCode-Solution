#include "std.h"

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int n = grid.size();
		if (n == 0) return 0;
		int m = grid[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int t = i==0&&j==0?0:0x3f3f3f3f;
				if (i > 0) t = min(t, grid[i - 1][j]);
				if (j > 0) t = min(t, grid[i][j - 1]);
				grid[i][j] += t;
			}
		}
		return grid[n - 1][m - 1];
	}
};