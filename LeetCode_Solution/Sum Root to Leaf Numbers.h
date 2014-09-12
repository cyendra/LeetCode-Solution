#include "std.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sum;
	void dfs(TreeNode *p,int num) {
		num = num * 10 + p->val;
		if (p->left == NULL&&p->right == NULL) sum += num;
		if (p->left != NULL) dfs(p->left, num);
		if (p->right != NULL) dfs(p->right, num);
	}

	int sumNumbers(TreeNode *root) {
		sum = 0;
		if (root == NULL) return sum;
		dfs(root, 0);
		return sum;
	}
};