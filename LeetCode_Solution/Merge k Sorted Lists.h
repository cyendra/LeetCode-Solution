#include "std.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	typedef pair<int, int> PII;
	typedef ListNode* pListNode;
	struct cmp
	{
		bool operator()(const pListNode& a, const pListNode& b)
		{
			return a->val > b->val;
		}
	};
	
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> que;
		int n = lists.size();
		ListNode *p,*head;
		head = NULL;
		for (int i = 0; i < n; i++)
		{
			if (lists[i] != NULL)
			{
				que.push(lists[i]);
			}
		}
		if (que.empty()) return head;
		head = que.top();
		p = head;
		que.pop();
		if (head->next != NULL) que.push(head->next);
		while (!que.empty())
		{
			ListNode* t = que.top();
			que.pop();
			p->next = t;
			p = p->next;
			if (t->next != NULL) que.push(p->next);
		}
		p->next = NULL;
		return head;
	}
};