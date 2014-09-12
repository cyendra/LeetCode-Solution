#include "std.h"

class Solution {
public:
	const static int INF = 0x3f3f3f3f;
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		if (n < 2) return 0;
		int lst = prices[0];
		int ans = 0;
		for (int i = 1; i < n; i++) {
			ans = max(ans, prices[i] - lst);
			lst = min(lst, prices[i]);
		}
		return ans;
	}
};

