class Solution {
public:
	typedef long long LL;
	bool isPalindrome(int x) {
		if (x < 0) return false;
		LL n = x;
		LL r = 0;
		while (n)
		{
			r = r * 10 + n % 10;
			n /= 10;
		}
		n = x;
		return n == r;
	}
};