# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def gao(self, head, k):
        cnt = 0
        p = head
        while p != None:
            p = p.next
            cnt += 1
        if cnt < k:
            return head, None
        p = head
        pre = p
        next = None
        tmp = None
        while k > 1 and p.next != None:
            tmp = next = p.next
            p.next = next.next
            next.next = pre
            pre = tmp
            k -= 1
        head = pre
        return head, p
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        head, p = self.gao(head, k)
        while p != None:
            lst = p
            p = p.next
            tmp, p = self.gao(p, k)
            lst.next = tmp
        return head