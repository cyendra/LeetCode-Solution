#include "std.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> v;
	TreeNode* build(int l, int r)
	{
		int mid = (l + r) / 2;
		TreeNode *p = new TreeNode(v[mid]);
		if (l <= mid - 1) p->left = build(l, mid - 1);
		else p->left = NULL;
		if (mid + 1 <= r) p->right = build(mid + 1, r);
		else p->right = NULL;
		return p;
	}
	TreeNode *sortedArrayToBST(vector<int> &num) {
		v = num;
		if (num.size() == 0) return NULL;
		return build(0, num.size() - 1);
	}
};