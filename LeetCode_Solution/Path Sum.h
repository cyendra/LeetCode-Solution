#include "std.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int Sum;
	bool dfs(TreeNode *p, int s)
	{
		if (p->left == NULL && p->right == NULL)
		{
			if (s + p->val == Sum) return true;
			else return false;
		}
		if (p->left != NULL) if (dfs(p->left, s + p->val)) return true;
		if (p->right != NULL) if (dfs(p->right, s + p->val)) return true;
		return false;
	}
	bool hasPathSum(TreeNode *root, int sum) {
		Sum = sum;
		if (root == NULL) return false;
		return dfs(root, 0);
	}
};