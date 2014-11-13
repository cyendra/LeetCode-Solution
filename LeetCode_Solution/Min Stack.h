#include <stack>
#include <map>
#include <algorithm>
#include <unordered_map>
class MinStack {
private:
	std::stack<int> stk;
	std::unordered_map<int, int>mp;
public:
	MinStack() {
		while (stk.size()) stk.pop();
		mp.clear();
	}
	void push(int x) {
		stk.push(x);
		mp[x]++;
	}

	void pop() {
		mp[stk.top()]--;
		stk.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return mp.begin()->first;
	}
};