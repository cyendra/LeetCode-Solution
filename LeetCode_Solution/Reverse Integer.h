class Solution {
public:
	int reverse(int x) {
		bool b = false;
		if (x < 0)
		{
			x = -x;
			b = true;
		}
		int ans = 0;
		while (x)
		{
			int t = x % 10;
			ans = ans * 10 + t;
			x /= 10;
		}
		if (b) ans = -ans;
		return ans;
	}
};