class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        m = len(matrix)
        if m==0:
            return res
        n = len(matrix[0])
        u = 0
        d = m-1
        l = 0
        r = n-1
        while(True):
            for i in range(l,r+1):
                res.append(matrix[u][i])
            u+=1
            if u>d: break
            for i in range(u,d+1):
                res.append(matrix[i][r])
            r-=1
            if r<l:break
            for i in range(r,l-1,-1):
                res.append(matrix[d][i])
            d-=1
            if d<u:break
            for i in range(d,u-1,-1):
                res.append(matrix[i][l])
            l+=1
            if l>r:break
        return res
