#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-10-31
# Author: bryce


#######转成字符一行就可以搞定
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        return str(x) == str(x)[::-1] 

      
      
########不转成字符求回文数表示
class Solution2(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        a = x
        n = 0   
        if a < 0:
            return False
        while a != 0:
            m = a % 10
            a /= 10
            n = n * 10 + m
        return x == n
