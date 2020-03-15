# 题目描述:  岛屿的最大面积

给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

**示例 :**
```
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
```
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

# 解题思路:
  dfs

# 时间复杂度：
  O(mn)
# 空间复杂度
O(mn) 递归的深度最大可能是整个网格的大小
  
# 代码

###  dfs
```c++
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i =0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j] == 1)
                {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
    int dfs (vector<vector<int>> &grid, int i, int j)
    {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
        {
            return 0;
        }
        grid[i][j] = 0 ;  // 用过的土地置为0，不允许再用
        int count = 1;
        count += dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid,i, j-1) + dfs(grid, i, j+1);
        return count;
    }
};
```
