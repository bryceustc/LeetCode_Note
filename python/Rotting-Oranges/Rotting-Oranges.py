class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        res = 0
        if grid == []:
            return res
        m = len(grid)
        n = len(grid[0])
        dx = [1,-1,0,0]
        dy = [0,0,1,-1]
        q=[]
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    q.append((i,j))
        while q:
            size = len(q)
            for i in range(size):
                d = q.pop(0)
                for k in range(4):
                    x = d[0] + dx[k]
                    y = d[1] + dy[k]
                    if 0<=x<m and 0<=y<n and grid[x][y]==1:
                        grid[x][y]=2
                        q.append((x,y))
            if q:
                res+=1
        for row in grid:
            for i in row:
                if i==1:
                    return -1
        return res
