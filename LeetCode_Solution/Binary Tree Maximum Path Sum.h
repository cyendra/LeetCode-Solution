#include "std.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	const static int INF = 0x3f3f3f3f;
	int ans;
	int dfs(TreeNode *p) {
		int res = p->val;
		if (p->left == NULL&&p->right == NULL) {
			ans = max(ans, res);
			return res;
		}
		if (p->left == NULL&&p->right != NULL) {
			res += max(0, dfs(p->right));
			ans = max(ans, res);
			return res;
		}
		if (p->left != NULL&&p->right == NULL) {
			res += max(0, dfs(p->left));
			ans = max(ans, res);
			return res;
		}
		
		int L = max(0, dfs(p->left));
		int R = max(0, dfs(p->right));
		ans = max(ans, L + R + res);
		res += max(L, R);
		return res;
	}
	int maxPathSum(TreeNode *root) {
		if (root == NULL) return 0;
		ans = -INF;
		dfs(root);
		return ans;
	}
};