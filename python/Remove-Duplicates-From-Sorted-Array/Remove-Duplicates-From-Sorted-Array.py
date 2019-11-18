#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-17
# Author: Bryce

######Python Solution 1:
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        n = len(nums)
        if n==0:
            return res
        k = 0
        for i in range(1,n):
            if nums[k] != nums[i]:
                k+=1
                nums[k] = nums[i]
        res = k+1
        return res
   
  
######Python Solution 2:
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        n = len(nums)
        if n==0:
            return res
        l = 0
        r = 0
        while r < n:
            if nums[l] == nums[r]:
                r+=1
            else:
                l+=1
                nums[l] = nums[r]
                r+=1
        res = l+1
        return res
