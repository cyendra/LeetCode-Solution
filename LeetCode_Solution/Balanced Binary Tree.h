#include "std.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool ok;
	int dfs(TreeNode* p)
	{
		if (p == NULL) return 0;
		if (p->left == NULL && p->right == NULL) return 1;
		int l = dfs(p->left);
		int r = dfs(p->right);
		if (abs(l - r) > 1) ok = false;
		return 1 + l + r;
	}
	bool isBalanced(TreeNode *root) {
		if (root == NULL) return true;
		ok = true;
		dfs(root);
		return ok;
	}
};