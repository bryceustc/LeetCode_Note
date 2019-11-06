#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-06
# Author: Bryce

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums= sorted(nums)
        res=[]
        k = 0
        while k < len(nums)-1:
            while k > 0 and k <= len(nums)-1 and nums[k] == nums[k-1]:
                k+=1
            l = k + 1
            r = len(nums) - 1
            while (l < r):
                if nums[k] + nums[l] + nums[r] == 0:
                    res.append([nums[k],nums[l],nums[r]])
                    while l < r and nums[l] == nums[l+1]:
                        l+=1
                    while l < r and nums[r] == nums[r-1]:
                        r-=1
                    l+=1
                    r-=1
                elif nums[k] + nums[l] + nums[r] < 0:
                    l+=1
                elif nums[k] + nums[l] + nums[r] > 0:
                    r-=1
            k+=1
        return res
