#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-1
# Author: bryce
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(s)==0 and len(p)==0:
            return True
        if len(s)!=0 and len(p)==0:
            return False
        if  len(p)>1 and p[1]=='*':
            if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
                return self.isMatch(s,p[2:]) or self.isMatch(s[1:],p)
            else:
                return self.isMatch(s,p[2:])
        if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
            return self.isMatch(s[1:],p[1:])
        else:
            return False
### Solution 2:
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n = len(s)
        m = len(p)
        import numpy
        dp = numpy.zeros((n+1,m+1)) 
        ### python 二维数组初始化  dp[[0 for _ in range(m+2)] for _ in range(n+2)]
        s = ' ' + s
        p = ' ' + p
        dp[0][0] = 1
        for i in range(n+1):
            for j in range(1,m+1):
                if i > 0 and (s[i]==p[j] or p[j]=='.'):
                    dp[i][j] = dp[i][j] or dp[i-1][j-1]
                if p[j]=='*':
                    if j>=2:
                        dp[i][j] = dp[i][j] or dp[i][j-2]
                    if i > 0 and (s[i]==p[j-1] or p[j-1]=='.'):
                        dp[i][j] = dp[i][j] or dp[i-1][j]
        return dp[n][m]
