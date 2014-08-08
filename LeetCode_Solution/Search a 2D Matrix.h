#include "std.h"

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int n = matrix.size();
		if (n == 0) return false;
		int m = matrix[0].size();
		int x = 1, y = m;
		while (x <= n && y >= 1) {
			if (matrix[x][y] == target) return true;;
			if (matrix[x][y] < target) x++;
			if (matrix[x][y] > target) y--;
		}
		return false;
	}
};