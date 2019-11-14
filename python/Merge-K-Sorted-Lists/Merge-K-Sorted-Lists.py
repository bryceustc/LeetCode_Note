#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-14
# Author: Bryce
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


######## Python Solution 1:
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        res =[]
        dummyHead = ListNode(0)
        temp = dummyHead
        k = len(lists)
        if k==0:
            return None
        if k==1:
            return lists[0]
        l1 = lists[0]
        l2 = lists[1]
        for i in range (1,k):
            l2 = lists[i]
            while l1 and l2:
                if l1.val < l2.val:
                    temp.next = l1
                    l1 = l1.next
                else:
                    temp.next = l2
                    l2 = l2.next
                temp = temp.next
            if l1:
                temp.next = l1
            else:
                temp.next = l2
            l1 = dummyHead.next
            temp = dummyHead
        res = dummyHead.next
        return res
      
######## Python Solution 2:(分治法)
