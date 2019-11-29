#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-25
# Author: Bryce

##### Python Solution 1: 两次二分法
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        res= [-1,-1]
        if n==0:
            return res
        start = 0
        end = n
        while end > start:
            mid=start + (end-start)//2
            if nums[mid]<target:
                start= mid +1
            else:
                end = mid
        if start == n or nums[start]!=target:
            return res
        res[0]=start
        start = 0
        end = n
        while end > start:
            mid = start + (end-start)//2
            if nums[mid]<=target:
                start=mid+1
            else:
                end = mid
        res[1] =end-1
        return res
        
  ##### Python Solution 2: 线性扫描，两次遍历，时间复杂度不满足要求
  class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        res= [-1,-1]
        if n==0:
            return res
        for i in range(n):
            if nums[i]== target:
                res[0] = i
                break
        if res[0] == -1:
            return res
        for j in range (n-1,-1,-1):
            if nums[j] == target:
                res[1]=j
                break
        return res
