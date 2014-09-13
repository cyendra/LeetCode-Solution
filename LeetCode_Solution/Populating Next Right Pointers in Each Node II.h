#include "std.h"

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	typedef pair<TreeLinkNode*, int> PTI;
	void connect(TreeLinkNode *root) {
		queue<PTI> que;
		if (root == NULL) return;
		int n = 0;
		que.push(make_pair(root, 1));
		TreeLinkNode *lst = root;
		while (!que.empty()) {
			PTI top = que.front();
			que.pop();
			TreeLinkNode *p = top.first;
			int id = top.second;
			if (id > n) lst->next = NULL;
			else lst->next = p;
			n = id;
			lst = p;
			if (p->left != NULL)que.push(make_pair(p->left, id + 1));
			if (p->right != NULL) que.push(make_pair(p->right, id + 1));
		}
		lst->next = NULL;
	}
};