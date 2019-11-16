#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-15
# Author: Bryce


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


################Python Solution 1: (非递归)
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res=[]
        dummyHead = ListNode(0)
        temp = dummyHead
        dummyHead.next = head
        while temp.next and temp.next.next:
            s1 = temp.next
            s2 = s1.next
            s = s2.next
            temp.next = s2
            s2.next = s1
            s1.next = s
            temp = temp.next.next
        res = dummyHead.next
        return res
      
################Python Solution 2: (递归)
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        res = head.next
        head.next = self.swapPairs(head.next.next)
        res.next = head
        return res
