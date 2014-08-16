#include "std.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	typedef pair<int, TreeNode*> PII;
	typedef vector<int> VI;
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		VI vec;
		queue<PII> que;
		int id = -1;
		if (root == NULL) return ans;
		que.push(make_pair(0, root));
		while (que.size())
		{
			PII t = que.front();
			que.pop();
			int idx = t.first;
			TreeNode *p = t.second;
			if (idx > id)
			{
				ans.push_back(vec);
				id = idx;
			}
			ans[id].push_back(p->val);
			if (p->left != NULL) que.push(make_pair(idx + 1, p->left));
			if (p->right != NULL) que.push(make_pair(idx + 1, p->right));
		}
		for (int i = 1; i < id; i++)
		{
			if (i & 1)
			{
				reverse(ans[i].begin(), ans[i].end());
			}
		}
		return ans;
	}
};