## Solution 1:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head==None or head.next==None:
            return head
        p = None
        cur = head
        temp = head.next
        while cur:
            temp = cur.next
            cur.next = p
            p = cur
            cur = temp
        return p
### Solution 2:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        else:
            newhead = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return newhead
