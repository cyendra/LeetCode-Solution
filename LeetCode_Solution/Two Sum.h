#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	struct data{
		int id;
		int v;
		bool operator<(const data b) const {
			return v < b.v;
		}
	};

	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<data> v;
		for (int i = 0; i<(int)numbers.size(); i++){
			data x;
			x.id = i;
			x.v = numbers[i];
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i<(int)v.size(); i++) {
			int fd = target - v[i].v;
			int l = i + 1, r = v.size();
			int ans2 = -1, ans1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (v[mid].v<fd) l = mid + 1;
				else if (v[mid].v>fd) r = mid - 1;
				else {
					ans1 = i;
					ans2 = mid;
					break;
				}
			}
			if (ans2 != -1) {
				vector<int> res;
				int p1 = v[ans1].id + 1, p2 = v[ans2].id + 1;
				if (p1 > p2) swap(p1, p2);
				res.push_back(p1);
				res.push_back(p2);
				return res;
			}
		}
	}
};