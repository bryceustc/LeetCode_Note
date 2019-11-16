#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-16
# Author: Bryce

##########  Python  Solution 1:
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        res = []
        dummmyHead = ListNode(0)
        pre = dummmyHead
        dummmyHead.next=head
        cur = head
        i = 1
        if head is None or k==1:
            return head
        while cur:
            if i%k == 0:
                pre = self.reverseOneGroup(pre,cur.next)
                cur = pre.next
            else:
                cur = cur.next
            i+=1
        res = dummmyHead.next
        return res
    def reverseOneGroup(self, pre, l):
        last = pre.next
        cur = last.next
        while cur != l:
            last.next = cur.next
            cur.next = pre.next
            pre.next = cur
            cur = last.next
        return last
