## Solution 1:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head==None or k<=0:
            return head
        temp = head
        n = 0
        while temp:
            n+=1
            temp = temp.next
        k = k%n
        temp = head
        for i in range(k):
            temp = self.rightMove(temp)
        return temp
    
    def rightMove(self,head):
        if head==None or head.next==None:
            return head
        prev = None
        cur = head
        temp = head
        while cur.next:
            prev = cur
            cur = cur.next
        prev.next = cur.next
        cur.next = temp
        return cur
## Solution 2:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head==None or k<=0:
            return head
        cur = head
        tail = None
        n = 0
        while cur:
            n+=1
            tail = cur
            cur = cur.next
        k = k%n
        tail.next = head
        cur = head
        for i in range(n-k-1):
            cur = cur.next
        head = cur.next
        cur.next = None
        return head
