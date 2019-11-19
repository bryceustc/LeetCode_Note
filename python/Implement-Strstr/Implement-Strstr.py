#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-19
# Author: Bryce

## Python Solution 1: （使用内置函数）
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        return haystack.find(needle)
  
  
## Python Solution 2: 
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        m = len(needle)
        n = len(haystack)
        if needle is None: return 0
        if haystack is None or m > n: return -1
        for i in range (0,n-m+1):
          if haystack[i:i+m] == needle:
            return i
        return -1
