## python Solution 1:
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0]* n for _ in range(n)]    ##python初始化二维数组
        out = [i for i in range(n*n,0,-1)]
        u = 0
        d = n-1
        l = 0
        r = n-1
        while True:  ## 可以改为while num<=pow(n,2): 更节省时间
            for i in range(l,r+1,1):
                res[u][i] = out[-1]
                #del out[-1]
                out.pop()
            u+=1
            if u>d:break
            for i in range(u,d+1,1):
                res[i][r] = out[-1]
                del out[-1]
            r-=1
            if r<l:break
            for i in range(r,l-1,-1):
                res[d][i] = out[-1]
                del out[-1]
            d-=1
            if d<u:break
            for i in range(d,u-1,-1):
                res[i][l]=out[-1]
                del out[-1]
            l+=1
            if l>r:break
        return res

      
## Python Solution 1 改进版：
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0]* n for _ in range(n)]    ##python初始化二维数组
        # res = [[0 for _ in range(n)] for _ in range(n)]
        u = 0
        d = n-1
        l = 0
        r = n-1
        m = pow(n,2)
        num = 1
        while num<=m:
            for i in range(l,r+1,1):
                res[u][i] = num
                num+=1
            u+=1
            for i in range(u,d+1,1):
                res[i][r] = num
                num+=1
            r-=1
            for i in range(r,l-1,-1):
                res[d][i] = num
                num+=1
            d-=1
            for i in range(d,u-1,-1):
                res[i][l]=num
                num+=1
            l+=1
        return res
