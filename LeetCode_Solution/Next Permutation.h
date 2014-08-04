#include "std.h"
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int n = num.size();
		if (n == 1) return;
		for (int i = n - 2; i >= 0; i--)
		{
			if (num[i] < num[i + 1])
			{
				int j = n - 1;
				while (num[j] <= num[i]) j--;
				swap(num[i], num[j]);
				j = n - 1;
				for (int k = i + 1; k < n; k++)
				{
					if (k < j) swap(num[k], num[j--]);
					else break;
				}
				return;
			}
		}
		for (int i = 0; i < n / 2; i++)
		{
			swap(num[i], num[n - i - 1]);
		}
	}
};