#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-23
# Author: Bryce


###############Python Solution 1:栈
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        stack = []
        start = 0
        res = 0
        for i in range (n):
            if s[i] == '(':
                stack.append(i)
            elif s[i] == ')':
                if stack:
                    stack.pop()
                    if stack:
                        res = max(res,i-stack[-1])
                    else:
                        res = max(res,i-start+1)
                else:
                    start = i+1
        return res
