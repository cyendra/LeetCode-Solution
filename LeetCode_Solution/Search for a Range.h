#include "std.h"

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int ans1 = -1, ans2 = n;
		int l = 0, r = n - 1, mid;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (A[mid] >= target)
			{
				ans1 = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		l = 0, r = n - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (A[mid] > target)
			{
				ans2 = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		vector<int> res;
		if (A[ans1] != target)
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		ans2--;
		res.push_back(ans1);
		res.push_back(ans2);
		return res;
	}
};