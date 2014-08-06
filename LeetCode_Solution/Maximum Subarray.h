#include "std.h"

class Solution {
public:
	int maxSubArray(int A[], int n) {
		int *f = new int[n];
		int ans = -0x3f3f3f3f;
		for (int i = 0; i < n; i++) f[i] = 0;
		for (int i = 0; i < n; i++)
		{
			if (i > 0) f[i] = max(f[i - 1] + A[i], A[i]);
			else f[i] = A[i];
			ans = max(ans, f[i]);
		}
		delete f;
		return ans;
	}
};