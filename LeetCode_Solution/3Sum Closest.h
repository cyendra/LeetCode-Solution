#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int n = num.size();
		int ans = 0x3f3f3f3f;
		int res = 0;
		for (int p = 0; p < n; p++) {
			int L = 0;
			int R = n - 1;
			while (L < R) {
				if (L == p) {
					L++;
					continue;
				}
				if (R == p) {
					R--;
					continue;
				}
				int sum = num[L] + num[R] + num[p];
				if (abs(sum - target) < ans) {
					ans = abs(sum - target);
					res = sum;
				}
				if (sum < target) {
					L++;
				}
				else if (sum > target) {
					R--;
				}
				else {
					ans = 0;
					res = sum;
					break;
				}
			}
		}
		return res;
	}
};