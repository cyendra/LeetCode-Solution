#include "std.h"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ans;
		int f[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		int n = matrix.size();
		if (n == 0) return ans;
		int m = matrix[0].size();
		if (n == 1) 
		{
			for (int i = 0; i < m; i++) ans.push_back(matrix[0][i]);
			return ans;
		}
		if (m == 1)
		{
			for (int i = 0; i < n; i++) ans.push_back(matrix[i][0]);
			return ans;
		}
		for (int i = 0; i < m; i++) ans.push_back(matrix[0][i]);
		int x = 0;
		int y = m - 1;
		int p = n * m - m;
		int d = 1;
		int b1 = n - 1;
		int b2 = m - 1;
		int cnt=0;
		while (p > 0) {
			for (int i = 0; i < b1; i++)
			{
				x += f[d][0];
				y += f[d][1];
				ans.push_back(matrix[x][y]);
				p--;
			}
			if (p == 0) break;
			d = (d + 1) % 4;
			for (int i = 0; i < b2; i++)
			{
				x += f[d][0];
				y += f[d][1];
				ans.push_back(matrix[x][y]);
				p--;
			}
			if (p == 0) break;
			d = (d + 1) % 4;
			b1--;
			b2--;
		}
		return ans;
	}
};