#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-03
# Author: Bryce
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
