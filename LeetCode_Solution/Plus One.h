#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> v(digits.rbegin(),digits.rend());
		int len = v.size();
		int p = 0;
		v[p]++;
		while (v[p] >= 10){
			v[p] -= 10;
			if (p < len - 1) v[++p] += 1;
			else if (p == len - 1) {
				v.push_back(1);
			}
		}
		reverse(v.begin(), v.end());
		return v;
	}
};