class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		int f[2];
		f[0] = 1;
		f[1] = 2;
		int cur = 1;
		for (int i = 3; i <= n; i++)
		{
			f[cur ^ 1] = f[cur] + f[cur ^ 1];
			cur ^= 1;
		}
		return f[cur];
	}
};