#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-07
# Author: Bryce


class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res = nums[0] + nums[1] + nums[2]
        diff = abs(res -target)
        n = len(nums)
        nums = sorted(nums)
        k = 0
        while k < n -2:
            i = k + 1
            j = n - 1
            while j > i:
                sum_res = nums[i] + nums[j] + nums[k]
                newDiff = abs(sum_res - target)
                if diff > newDiff : 
                    diff = newDiff
                    res = sum_res
                if sum_res < target:
                    i += 1
                else:
                    j -= 1
            k +=1
        return res
