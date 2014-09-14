#include "std.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode *p = new ListNode(0);
		ListNode *h = p;
		while (l1 != NULL && l2 != NULL) {
			p->val += l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
			if (l1 != NULL || l2 != NULL) p->next = new ListNode(0);
			if (p->val >= 10) {
				p->val -= 10;
				if (p->next != NULL) p->next->val += 1;
				else p->next = new ListNode(1);
			}
			p = p->next;
		}
		if (l1 == NULL && l2 == NULL) return h;
		ListNode *lst;
		if (l1 != NULL) lst = l1;
		else lst = l2;
		while (lst != NULL) {
			p->val += lst->val;
			lst = lst->next;
			if (lst != NULL) p->next = new ListNode(0);
			if (p->val >= 10) {
				p->val -= 10;
				if (p->next != NULL) p->next->val += 1;
				else p->next = new ListNode(1);
			}
			p = p->next;
		}
		return h;
	}
};