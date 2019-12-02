#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-12-2
# Author: Bryce


### Python Solution 1:
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)-1
        start = 1
        end = n
        while end > start:
            mid = start + (end-start)//2
            k = 0
            for num in nums:
                if num<=mid and num>=start:
                    k+=1
            if k > mid-start+1:
                end = mid
            else:
                start = mid +1
        return start
      
      
##### Python Solution 2:
 class Solution:
    def findDuplicate(self, nums: List[int]) -> int:       
        res = 0
        nums = sorted(nums)
        for i in range(1,len(nums)):
            if nums[i] == nums[i-1]:
                res = nums[i]
                break
        return res
      
####Python Solution 3:
        dic = {}
        res = 0
        for index,num in enumerate(nums):
            if num in dic:
                res = num
            else:
                dic[num]=index
        return res
