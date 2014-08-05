class Solution {
public:
	double pow(double x, int n) {
		double ans = 1.0;
		if (n > 0)
		{
			while (n > 0)
			{
				if (n & 1) ans *= x;
				x *= x;
				n >>= 1;
			}
		}
		else if (n < 0)
		{
			n = -n;
			while (n > 0)
			{
				if (n & 1) ans *= x;
				x *= x;
				n >>= 1;
			}
			ans = 1 / ans;
		}
		return ans;
	}
};