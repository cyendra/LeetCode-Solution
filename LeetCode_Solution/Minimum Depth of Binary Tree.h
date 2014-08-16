#include "std.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode *root) {
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL) return 1;
		int rs = 0x3f3f3f3f;
		if (root->left != NULL) rs = min(rs, minDepth(root->left));
		if (root->right != NULL) rs = min(rs, minDepth(root->right));
		return rs + 1;
	}
};