#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-10
# Author: Bryce




# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummyHead = ListNode(0)
        dummyHead.next = head
        p = dummyHead
        q = dummyHead
        for i in range (n+1):
            q = q.next
        while q:
            p = p.next
            q = q.next
        p.next = p.next.next
        res = dummyHead.next
        return res
