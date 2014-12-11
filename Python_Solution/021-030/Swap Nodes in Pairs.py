# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        cur = tmp = pre = None
        cur = head
        if cur != None and cur.next != None:
            head = cur.next
        while cur != None:
            if cur.next == None:
                return head
            next = cur.next
            if pre != None:
                pre.next = next
            tmp = next.next
            next.next = cur
            cur.next = tmp
            pre = cur
            cur = cur.next
        return head

sol = Solution()
print sol.swapPairs({})