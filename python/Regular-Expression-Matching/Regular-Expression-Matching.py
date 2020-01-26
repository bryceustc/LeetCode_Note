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
