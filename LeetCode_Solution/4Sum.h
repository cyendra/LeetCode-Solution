#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		set<long long> st;
		sort(num.begin(), num.end());
		vector<vector<int> > res;
		int n = num.size();
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++) {
				int L = j + 1;
				int R = n - 1;
				while (L < R) {
					int sum = num[i] + num[j] + num[L] + num[R];
					if (sum < target) {
						while (L + 1 < R && num[L + 1] == num[L]) L++;
						L++;
					}
					else if (sum > target) {
						while (L < R - 1 && num[R - 1] == num[R]) R--;
						R--;
					}
					else {
						vector<int> v = { num[i], num[j], num[L], num[R] };
						res.push_back(v);
						while (L + 1 < R && num[L + 1] == num[L]) L++;
						L++;
						while (L < R - 1 && num[R - 1] == num[R]) R--;
						R--;
					}
				}
				while (j + 1 < n && num[j + 1] == num[j]) j++;
			}
			while (i + 1 < n && num[i + 1] == num[i]) i++;
		}
		return res;
	}
};