class Solution {
public:
	typedef long long LL;
	int divide(int dividend, int divisor) {
		int ans = 0;
		bool b = 0;
		LL x = dividend;
		LL y = divisor;
		if (x < 0)
		{
			x = -x;
			b ^= 1;
		}
		if (y < 0)
		{
			y = -y;
			b ^= 1;
		}
		if (y == 0) return 0;
		if (x < y) return 0;
		while (x >= y)
		{
			LL sum = y;
			int cnt=1;
			while (sum + sum <= x)
			{
				sum += sum;
				cnt += cnt;
			}
			x -= sum;
			ans += cnt;
		}
		if (b) ans = -ans;
		return ans;
	}
};