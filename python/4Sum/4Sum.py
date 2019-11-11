#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-09
# Author: Bryce
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        nums = sorted(nums)
        n = len(nums)
        if n < 3:
            return res
        for i in range(n-3):
            if i>0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1,n-2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                l = j+1
                r = n-1
                while l<r:
                    sum_nums = nums[i]+nums[j]+nums[l]+nums[r]
                    if sum_nums == target:
                        res.append([nums[i],nums[j],nums[l],nums[r]])
                        while l < r and nums[l] == nums[l+1]:
                            l+=1
                        while l < r and nums[r] == nums[r-1]:
                            r-=1
                        l+=1
                        r-=1
                    if sum_nums < target:
                        l+=1
                    if sum_nums > target:
                        r-=1
        return res
