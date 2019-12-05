#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-12-3
# Author: Bryce

#### Python Solution 1:
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        if n==0:
          return res
        for i in range (1,n-1):
            max_left = 0
            max_right = 0
            for j in range (i-1,-1,-1):
                if height[j] > max_left:
                    max_left = height[j]
            for k in range (i+1,n,1):
                if height[k] > max_right:
                    max_right = height[k]
            min_height = min(max_left,max_right)
            if min_height > height[i]:
                res += min_height - height[i]
        return res
      
      
## Python Solution 2:
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n==0:
          return 0
        res = 0
        max_left = [0 for x in range(n)]
        max_right = [0 for y in range(n)]
        for i in range(1,n):
            max_left[i] = max(max_left[i-1],height[i-1])
        for j in range(n-2,-1,-1):
            max_right[j] = max(max_right[j+1],height[j+1])
        for i in range(1,n-1):
            min_height= min(max_left[i],max_right[i])
            if min_height > height[i]:
                res += min_height - height[i]
        return res
      
      
      
#### Python Solution 3:
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n==0:
          return 0
        res = 0
        max_left = 0
        max_right = 0
        left = 1
        right = n-2
        while right >= left:
            if height[left-1] < height[right+1]:
                max_left = max(max_left,height[left-1])
                min_height = max_left
                if min_height > height[left]:
                    res += min_height - height[left]    
                left += 1
            else:
                max_right = max(max_right,height[right+1])
                min_height = max_right
                if min_height > height[right]:
                    res += min_height - height[right] 
                right -= 1
        return res
