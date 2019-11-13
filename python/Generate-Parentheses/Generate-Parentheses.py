#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-13
# Author: Bryce


###Python Solution 1:
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        out = ""
        if n==0:
            return res
        res = self.DFS(n,n,out,res)
        return res
    def DFS(self,l,r,out,res):
        if l == 0 and r == 0:
            res.append(out)
        if l > 0:
            self.DFS(l-1,r,out+'(',res)
        if r > 0 and r > l:
            self.DFS(l,r-1,out+')',res)
        return res
