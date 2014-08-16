#include "std.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode *root) {
		if (root == NULL) return 0;
		int rs = 0;
		if (root->left != NULL)	rs = max(rs, maxDepth(root->left));
		if (root->right != NULL) rs = max(rs, maxDepth(root->right));
		return rs + 1;
	}
};