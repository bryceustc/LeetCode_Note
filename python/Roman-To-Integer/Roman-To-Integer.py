#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-04
# Author: Bryce
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        words = {}
        res = 0
        i = 0
        words['I'] = 1; words['V'] = 5;
        words['X'] = 10; words['L'] = 50; 
        words['C'] = 100; words['D'] = 500;
        words['M'] = 1000;
        
        while i < len(s):
            if i + 1 < len(s) and words[s[i+1]] > words[s[i]]:
                res += words[s[i+1]] - words[s[i]]
                i +=2
            else:
                res += words[s[i]]
                i += 1
        return res
