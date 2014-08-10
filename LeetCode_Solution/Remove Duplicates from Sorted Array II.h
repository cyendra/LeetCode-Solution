#include "std.h"

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int cnt = 0;
		int lst = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (cnt==0 || A[i] != lst)
			{
				lst = A[i];
				cnt = 1;
				A[ans++]=A[i];
			}
			else if (A[i] == lst)
			{
				cnt++;
				if (cnt <= 2) A[ans++]=A[i];
			}
		}
		return ans;
	}
};