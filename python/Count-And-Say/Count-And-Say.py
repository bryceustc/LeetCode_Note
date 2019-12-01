#! /usr/bin/env python
#! -*- coding=utf-8 -*-
# Date: 2019-11-29
# Author: Bryce


###########Python Solution 1:
class Solution:
    def countAndSay(self, n: int) -> str:
        if n==0: return ""
        res = '1'
        for i in range(1,n):
            temp, num, count = '', res[0], 1
            for j in range(1,len(res)):
                if res[j] == num:count += 1
                else:
                    temp += str(count) + num
                    num = res[j]
                    count = 1
            temp += str(count) + num
            res = temp
        return res
      
###########Python Solution 2:

class Solution:
    def countAndSay(self, n: int, res='1') -> str:
        return res if n == 1 else self.countAndSay(n-1, ''.join([str(len(list(gen)))+val for val, gen in groupby(res)])
