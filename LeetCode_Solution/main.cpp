#include "std.h"
#include "Word Ladder.h"
#include <unordered_set>
using namespace std;


int main()
{
	unordered_set<string> st;
	Solution sol;
	string s, e;
	string tmp;
	int n;
	
	cin >> s >> e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		st.insert(tmp);
	}
	
	cout << sol.ladderLength(s, e, st);

	return 0;
}