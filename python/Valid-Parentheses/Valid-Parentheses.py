#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-11
# Author: Bryce

### Python Solution 1:
class Solution:
    def isValid(self, s):
        while '{}' in s or '()' in s or '[]' in s:
            s = s.replace('{}', '')
            s = s.replace('[]', '')
            s = s.replace('()', '')
        return s == ''

      
### Python Solution 2:
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) & 1 == 1:  # 位运算判断奇偶
            return False
        stack = []
        hash_map = {'(': ')', '[': ']', '{': '}'}
        for c in s:
            if c in hash_map:
                stack.append(c)
                continue
            elif stack and hash_map[stack[-1]] == c:
                stack.pop()
            else:
                return False
        return not stack
