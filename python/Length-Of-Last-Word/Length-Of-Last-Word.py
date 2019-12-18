### Python Solution 1:
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res =0
        n=len(s)
        if n==0:
            return res
        m = n-1
        while m>=0 and s[m]==' ':
            m-=1
        for i in range (m,-1,-1):
            if s[i]==' ':
                break
            res+=1
        return res

 ### Python Solution 2:
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = 0
        s = s.strip(' ')
        s = s.split(' ')
        res = len(s[-1])
        return res
