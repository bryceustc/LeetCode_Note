#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-03
# Author: Bryce

#Python Solution 1:
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        res = ''
        val= [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        for i in range(0,len(roman)):
            while num >= val[i] :
                num -= val[i]
                res += roman[i]
        return res
    
    
#Python Solution 2:
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        res = 0
        if len(height) < 2:
            return 0
        i = 0
        j = len(height) -1
        while i < j:
            width = j - i
            high = min (height[i],height[j])
            res =  max(res, width * high)
            if height[i] > height[j]:
                j -=1
            else:
                i +=1
        return res
