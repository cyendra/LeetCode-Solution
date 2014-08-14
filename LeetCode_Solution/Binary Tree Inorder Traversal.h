#include "std.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> ans;
	void dfs(TreeNode* p){
		if (p->left != NULL) dfs(p->left);
		ans.push_back(p->val);
		if (p->right != NULL) dfs(p->right);
	}
	vector<int> inorderTraversal(TreeNode *root) {
		ans.clear();
		if (root == NULL) return ans;
		dfs(root);
		return ans;
	}
};