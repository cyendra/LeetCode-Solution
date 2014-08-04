class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int l = 0, r = n - 1, ans = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (A[mid] >= target)
			{
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		return ans;
	}
};