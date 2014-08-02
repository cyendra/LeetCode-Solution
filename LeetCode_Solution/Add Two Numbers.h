#include "std.h"

class Solution {
public:
	const static int SIZE = 100003;
	const static int SEED = 13331;
	const static int MAX_N = 50000 + 10;
	typedef unsigned long long ULL;
	ULL H[MAX_N];
	ULL XL[MAX_N];
	int len;
	char s[MAX_N];
	void build(char *s){
		len = strlen(s);
		H[len] = 0;
		XL[0] = 1;
		for (int i = len - 1; i >= 0; i--){
			H[i] = H[i + 1] * SEED + s[i];
			XL[len - i] = XL[len - i - 1] * SEED;
		}
	}
	ULL hash(int i, int L){
		return H[i] - H[i + L] * XL[L];
	}

	int lcp(int i, int j){
		if (j >= len || i >= len) return 0;
		if (s[i] == '$' || s[j] == '$') return 0;
		int l = 0, r = min(len - i, len - j);
		int res = 0;
		while (l <= r){
			int mid = (l + r) / 2;
			if (hash(i, mid) == hash(j, mid)){
				res = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		return res;
	}
	string longestPalindrome(string str) {
		string res;
		int n = str.length();
		for (int i = 0; i < n; i++) s[i] = str[i];
		s[n] = '$';
		for (int i = 0; i<n; i++) s[n + i + 1] = s[n - i - 1];
		s[2 * n + 1] = 0;
		build(s);
		int ed = 2 * n + 1;
		int ans = 0;
		int idx = 0;
		for (int i = 0; i<n; i++){
			ed--;
			int lp = lcp(i + 1, ed + 1);
			int rs = 2 * lp + 1;
			if (rs>ans){
				ans = rs;
				idx = i - lp;
			}
			lp = lcp(i + 1, ed);
			rs = 2 * lp;
			if (rs>ans){
				ans = rs;
				idx = i - lp + 1;
			}
		}
		for (int i = 0; i < ans; i++) res.push_back(s[idx + i]);
		return res;
	}
};