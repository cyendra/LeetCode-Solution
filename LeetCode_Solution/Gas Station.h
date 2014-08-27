#include "std.h"

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		vector<int> a;
		int n = gas.size();
		for (int i = 0; i < n; i++)
		{
			a.push_back(gas[i] - cost[i]);
		}
		for (int i = 0; i < n; i++)
		{
			a.push_back(a[i]);
		}
		int sum = 0;
		int cnt = 0;
		int ans = 0;
		int p = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			if (sum + a[i] >= 0)
			{
				cnt++;
				if (cnt > ans)
				{
					ans = cnt;
					p = i;
				}
				sum += a[i];
			}
			else
			{
				sum = 0;
				cnt = 0;
			}
			if (ans == n) break;
		}
		if (ans >= n)
		{
			return p + 1 - n;
		}
		else
		{
			return -1;
		}
	}
};
