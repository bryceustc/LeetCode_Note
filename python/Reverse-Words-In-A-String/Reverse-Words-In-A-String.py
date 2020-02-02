class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s)
        n = len(s)
        self.Reverse(s,0,n-1)
        i =0
        while i<n:
            while i<n and s[i]==' ':
                i+=1
            start = end = i
            while i<n and s[i]!= ' ':
                i+=1
                end+=1
            self.Reverse(s,start,end-1)
        s = self.cleanSpaces(s)
        return s
    def Reverse(self,s,start,end):
        while start<end:
            s[start],s[end] = s[end],s[start]
            start+=1
            end-=1
    def cleanSpaces(self,s):
        n = len(s)
        i=0
        j=0
        while j<n:
            while j<n and s[j]==' ':
                j+=1
            while j<n and s[j]!=' ':
                s[i]=s[j]
                i+=1
                j+=1
            while j<n and s[j]==' ':
                j+=1
            if j<n:
                s[i] = ' '
                i+=1
        return "".join(s[:i])
### Solution 2:
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
