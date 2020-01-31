# Solution 1:
class Solution:
    def countDigitOne(self, n: int) -> int:
        res = 0
        for i in range(1,n+1):
            res+=self.NumberOf1(i)
        return res
    def NumberOf1(self, n: int):
        num = 0
        while n>0:
            if (n%10==1):
                num+=1
            n//=10
        return num
# Solution 2:
class Solution:
    def countDigitOne(self, n: int) -> int:
        res = 0
        i = 1
        while i<=n:
            a = n // i
            b = n % i
            res += (a+8)//10*i + (a%10==1)*(b+1)
            i*=10
        return res
# Solution 3:
# -*- coding:utf-8 -*-
class Solution:
    def countDigitOne(self, n: int) -> int:
        # write code here
        res = 0
        for i in range(1,n+1):
            s = str(i)
            res+=s.count('1')
        return res
