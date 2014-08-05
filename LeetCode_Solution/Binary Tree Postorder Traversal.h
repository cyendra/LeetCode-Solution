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
		if (left != NULL) dfs(t->left);
		if (right != NULL) dfs(t->right);
		v.push_back(t->val);
	}
	vector<int> postorderTraversal(TreeNode *root) {
		dfs(root);
		return v;
	}
};