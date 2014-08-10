#include "std.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return head;
		ListNode* p = head;
		while (p!=NULL && p->next != NULL)
		{
			while (p->next!=NULL && p->val == p->next->val) p->next = p->next->next;
			p = p->next;
		}
		return head;
	}
};