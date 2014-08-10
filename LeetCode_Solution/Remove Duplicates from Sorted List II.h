#include "std.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		bool go = false;
		while (head!=NULL){
			go = false;
			while (head != NULL && head->next != NULL && head->val == head->next->val){
				go = true;
				head = head->next;
			}
			if (go) head = head->next;
			else break;
		}
		if (head == NULL) return head;
		if (head->next == NULL) return head;
		ListNode *lst = head;
		ListNode *p = head->next;
		while (p!=NULL)
		{
			go = false;
			while (p != NULL&&p->next != NULL&&p->val == p->next->val){
				go = true;
				p = p->next;
			}
			if (go) p = p->next;
			else {
				lst->next = p;
				lst = lst->next;
				if (p!=NULL) p = p->next;
			}
		}
		if (lst!=NULL)lst->next = NULL;
		return head;
	}
};