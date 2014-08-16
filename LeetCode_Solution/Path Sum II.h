#include "std.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> path;
	vector<vector<int> >ans;
	int Sum;
	void dfs(TreeNode *p, int s)
	{
		if (p->left == NULL&&p->right == NULL)
		{
			if (s + p->val == Sum) ans.push_back(path);
			return;
		}
		if (p->left != NULL)
		{
			path.push_back(p->left->val);
			dfs(p->left, s + p->val);
			path.pop_back();
		}
		if (p->right != NULL)
		{
			path.push_back(p->right->val);
			dfs(p->right, s + p->val);
			path.pop_back();
		}
	}
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		Sum = sum;
		if (root == NULL) return ans;
		path.push_back(root->val);
		dfs(root, 0);
		return ans;
	}
};