class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        if n==0:
            return False
        num = False
        numAfterE = False
        decimal = False
        sign = False
        hasE = False
        for i in range(n):
            if s[i]==' ':
                if (i<n-1 and s[i+1]!=' ' and (num or decimal or sign or hasE)):
                    return False
            elif s[i]=='+' or s[i]=='-':
                if i>0 and s[i-1]!='e' and s[i-1]!=' ':
                    return False
                sign = True
            elif s[i]>='0' and s[i]<='9':
                num =True
                numAfterE=True
            elif s[i]=='.':
                if hasE or decimal:
                    return False
                decimal = True
            elif s[i]=='e':
                if hasE or (num is False):
                    return False
                hasE = True
                numAfterE=False
            else:
                return False
        return num and numAfterE
