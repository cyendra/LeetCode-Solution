#include "std.h"
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int n = height.size();
		if (n == 0) return 0;
		int *f = new int[n + 2];
		int *g = new int[n + 2];
		int *a = new int[n + 2];
		for (int i = 0; i <= n + 1; i++) f[i] = 0, g[i] = 0;
		for (int i = 1; i <= n; i++) a[i] = height[i - 1];
		a[0] = 0;
		a[n + 1] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] <= a[i - 1]) f[i] = f[i - 1] + 1;
			else f[i] = 1;
		}
		for (int i = n; i >= 1; i--)
		{
			if (a[i] <= a[i + 1]) g[i] = g[i + 1] + 1;
			else g[i] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, (f[i] + g[i] - 1) * a[i]);
		}
		return ans;
	}
};