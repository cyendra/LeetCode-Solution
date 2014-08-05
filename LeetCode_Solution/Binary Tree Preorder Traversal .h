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
	void dfs(TreeNode* t){
		if (t == NULL) return;
		v.push_back(t->val);
		if (left != NULL) dfs(t->left);
		if (right != NULL) dfs(t->right);
	}
	vector<int> preorderTraversal(TreeNode *root) {
		dfs(root);
		return v;
	}
};