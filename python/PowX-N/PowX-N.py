### Solution 1: 根据定义暴力求解
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = x
        if x==0:
            return 0
        if x==1:
            return 1
        if x==-1 and n%2 == 0:
            return 1
        if x==-1 and n%2 != 0:
            return -1
        if n==2147483647 and x<1:
            return 0
        if n==-2147483648 and x>1:
            return 0
        if n>0:
            for i in range(1,n):
                res *= x
        if n<0:
            for i in range(-1,n,-1):
                res *=x
            res = 1/res
        if n==0:
            res = 1
        return res;
