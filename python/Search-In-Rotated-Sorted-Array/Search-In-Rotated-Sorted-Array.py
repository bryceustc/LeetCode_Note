#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-24
# Author: Bryce


######Python Solution 1: 
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n==0 : return -1
        start = 0
        end = n - 1
        while end>=start:
            mid = start + (end - start)/2
            mid = int(mid)
            if nums[mid]==target:
                return mid
            if nums[mid]<nums[end]:
                if nums[mid]<target and nums[end]>=target:
                    start = mid + 1
                else:
                    end = mid-1;
            else:
                if nums[start]<=target and nums[mid]>target:
                    end = mid-1;
                else:
                    start = mid+1;
        return -1;

######Python Solution 2:    
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n==0 : return -1
        start = 0
        end = n - 1
        while end>=start:
            mid = start + (end - start)//2
            #mid = int(mid)
            if nums[mid]==target:
                return mid
            if nums[mid]>=nums[start]:
                if nums[start]<=target and nums[mid] > target:
                    end = mid - 1
                else:
                    start = mid+1
            else:
                if nums[mid]<target and nums[end]>= target:
                    start = mid +1
                else:
                    end = mid - 1
        return -1
