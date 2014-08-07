#include "std.h"

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > mat;
		mat.resize(n);
		for (int i = 0; i < n; i++){
			mat[i].resize(n);
		}
		int f[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		if (n == 0) return mat;
		int cnt = 0;
		for (int i = 0; i < n; i++) mat[0][i] = ++cnt;
		int x = 0;
		int y = n - 1;
		int p = n * n - n;
		int d = 1;
		int b1 = n - 1;
		int b2 = n - 1;
		while (p > 0) {
			for (int i = 0; i < b1; i++)
			{
				x += f[d][0];
				y += f[d][1];
				mat[x][y] = ++cnt;
				p--;
			}
			if (p == 0) break;
			d = (d + 1) % 4;
			for (int i = 0; i < b2; i++)
			{
				x += f[d][0];
				y += f[d][1];
				mat[x][y] = ++cnt;
				p--;
			}
			if (p == 0) break;
			d = (d + 1) % 4;
			b1--;
			b2--;
		}
		return mat;
	}
};