class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        n = len(A)
        m = len(B)
        if n!=m:
            return False
        if A=="" and B=="":
            return True
        for i in range(n):
            A = self.leftmove(A)
            if A==B:
                return True
        return False
    
    def leftmove(self,s):
        s = list(s)
        n = len(s)
        temp = s[0]
        for i in range(n):
            if i!=n-1:
                s[i]=s[i+1]
            else:
                s[i]=temp
        return ''.join(s)
## Solution 2：
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        n = len(A)
        m = len(B)
        if n!=m:
            return False
        if A=="" and B == "":
            return True
        if B in (A+A):
            return True
        return False
