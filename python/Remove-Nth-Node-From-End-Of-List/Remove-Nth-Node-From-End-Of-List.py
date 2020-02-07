#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-10
# Author: Bryce




# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#### Python Solution 1: (一次遍历)
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head == None:
            return None
        dummyHead = ListNode(0)
        dummyHead.next = head
        p = dummyHead
        q = dummyHead
        for i in range (n):
            q = q.next
        while q.next:
            p = p.next
            q = q.next
        p.next = p.next.next
        res = dummyHead.next
        return res
    
    
##### Python Solution 2：(二次遍历)
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head == None:
            return None
        temp1 = head
        temp2 = head
        length = 0
        m = 0
        while temp1:
            length +=1
            temp1 = temp1.next
        if n == length : return head.next
        while temp2:
            m+=1
            if m == length - n:
                temp2.next = temp2.next.next
                break
            temp2 = temp2.next
        return head
