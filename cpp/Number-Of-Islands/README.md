# 题目描述:  岛屿数量

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

**示例 :**
```
输入:
11110
11010
11000
00000

输出: 1
```

**示例 :**
```
输入:
11000
11000
00100
00011

输出: 3
```

# 解题思路:
  典型的dfs模板题，掌握
  
# 代码

###  dfs
```c++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]=='1')
                {
                    dfs(grid,i,j);//(遍历所有相邻为1的网格，设为0) 整体为一个岛屿
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
};
```

