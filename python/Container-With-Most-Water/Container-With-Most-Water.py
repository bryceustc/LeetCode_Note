#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-02
# Author: Bryce
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        res = 0
        if len(height) < 2:
            return 0
        for i in range(0,len(height)):
            j = i
            for j in range(0,len(height)):
                width = j - i
                high = min (height[i],height[j])
                res =  max(res, width * high)
        return res
