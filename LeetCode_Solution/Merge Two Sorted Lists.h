#include "std.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* head;
		if (l1->val < l2->val)
		{
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			l2 = l2->next;
		}
		ListNode* p = head;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
				p = p->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
				p = p->next;
			}
		}
		while (l1 != NULL)
		{
			p->next = l1;
			l1 = l1->next;
			p = p->next;
		}
		while (l2 != NULL)
		{
			p->next = l2;
			l2 = l2->next;
			p = p->next;
		}
		p->next = NULL;
		return head;
	}
};