#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
private:
	int count(string& s, int p){
		int cnt = 1;
		int len = s.length();
		//cout << "p=" << p << " ";
		//cout << s[p] << s[p + 1] << endl;
		while  (p + 1 < len && s[p] == s[p + 1]) {
			cnt++;
			
			p++;
		}
		//cout << "cnt = " << cnt << endl;
		return cnt;
	}
	string gao(string& s) {
		string ans;
		int p = 0;
		int len = s.length();
		while (p < len){
			//cout << "p=" << p << endl;
			int cnt = count(s, p);
			stringstream buf;
			string tmp;
			buf << cnt;
			buf >> tmp;
			std::for_each(tmp.begin(), tmp.end(), [&ans](char c){
				ans += c;
			});
			ans += s[p];
			p += cnt;
			//cout << p << endl;
		}
		return ans;
	}
public:
	string countAndSay(int n) {
		string b = "1";
		for (int i = 1; i < n; i++) {
			b = gao(b);
			//cout << endl;
		}
		return b;
	}
};