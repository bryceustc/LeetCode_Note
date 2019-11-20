#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-20
# Author: Bryce

class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        res = 0
        x = divisor
        y = dividend
        if x==0:
             return 2147483647
        if y==-2147483648 and x == -1:
            return 2147483647
        x = abs(x)
        y = abs(y)
        while (y>=x):
            temp = x
            s = 1
            while y > temp + temp:
                temp+=temp
                s+=s
            res+=s
            y-=temp
        if (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0):
            res*=-1
        return res
