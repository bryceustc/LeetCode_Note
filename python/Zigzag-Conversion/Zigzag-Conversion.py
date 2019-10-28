#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 8/12/19
# Author: Bryce
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        n = len(s)
        res = ""
        if numRows == 1:
            return s
        m = 2 * numRows -2       
        for i in range (numRows):
            if (i == 0 or i == numRows-1):
                for j in range (i,n,m):
                    res += s[j]
            else:
                j = i
                k = 2*numRows -i -1 -1
                while (j < n or k < n ):
                    if j < n:
                        res += s[j]
                    if k < n:
                        res += s[k]
                    j += m
                    k += m
        return res
