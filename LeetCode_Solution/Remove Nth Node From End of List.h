#include "std.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int num;
	int nth;
	void dfs(int dep, ListNode *p)
	{
		if (p->next != NULL)
		{
			dfs(dep + 1, p->next);
		}
		else
		{
			num = dep;
		}
		if (dep == num - nth)
		{
			ListNode *t = p->next;
			p->next = t->next;
			//delete t;
		}
	}
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		num = 0;
		nth = n;
		if (head != NULL) dfs(1, head);
		if (num == 1 && nth == 1) return head->next;
		return head;
	}
};