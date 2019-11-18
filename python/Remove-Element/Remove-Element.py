#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-18
# Author: Bryce

######Python Solution 1:
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        res = 0
        k = 0
        n = len(nums)
        if n == 0:
            return res
        for i in range(n):
            if nums[i] != val:
                nums[k] = nums[i]
                k+=1
        res = k
        return res
      
######Python Solution 2:
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        j=len(nums)
        for i in range(j-1,-1,-1):  ## 倒序
            if nums[i]==val: 
                nums.pop(i)       ###pop() 函数用于移除列表中的一个元素（默认最后一个元素），并且返回该元素的值。
        return len(nums)
