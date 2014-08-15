#include "std.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool dfs(int L, int R, TreeNode* root){
		if (root == NULL) return true;
		bool ok = true;
		if (root->left != NULL){
			if (root->left->val < root->val && root->left->val > L)
			{
				if (!dfs(L,root->val,root->left)) ok = false;
			}
			else
			{
				return false;
			}
		}
		if (root->right != NULL){
			if (root->right->val > root->val && root->right->val < R)
			{
				if (!dfs(root->val,R,root->right)) ok = false;
			}
			else
			{
				return false;
			}
		}
		return ok;
	}
	bool isValidBST(TreeNode *root) {
		if (root == NULL) return true;
		int L = 0;
		int R = 0x3f3f3f3f;
		TreeNode*p = root;
		while (p->left != NULL) p = p->left;
		L = p->val - 1;
		p = root;
		while (p->right != NULL) p = p->right;
		R = p->val + 1;
		return dfs(L,R,root);
	}
};