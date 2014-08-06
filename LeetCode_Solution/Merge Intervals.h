#include "std.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	struct Fun{
		bool operator()(const Interval& a, const Interval& b) const{
			if (a.start == b.start)
			{
				return a.end < b.end;
			}
			return a.start < b.start;
		}
	};
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ans;
		sort(intervals.begin(), intervals.end(), Fun());
		int n = intervals.size();
		if (n == 0) return ans;
		int l = intervals[0].start;
		int r = intervals[0].end;
		for (int i = 1; i < n; i++)
		{
			if (intervals[i].start <= r)
			{
				r = max(r, intervals[i].end);
			}
			else
			{
				ans.push_back(Interval(l, r));
				l = intervals[i].start;
				r = intervals[i].end;
			}
		}
		ans.push_back(Interval(l, r));
		return ans;
	}
};