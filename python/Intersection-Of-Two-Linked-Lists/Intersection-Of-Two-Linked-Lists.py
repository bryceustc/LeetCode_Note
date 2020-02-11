# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA==None or headB == None:
            return None
        p = headA
        q = headB
        n =0
        m=0
        while p:
            n+=1
            p = p.next
        while q:
            m+=1
            q = q.next
        p = headA
        q = headB
        k = 0
        if n>=m:
            k = n-m
        else:
            p = headB
            q = headA
            k = m-n
        for i in range(k):
            p = p.next
        while p and q and p!=q:
            p = p.next
            q = q.next
        res = p
        return res
