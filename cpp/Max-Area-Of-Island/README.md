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
  O(n)
# 空间复杂度
  
  1: O(1)
  
  2:O(n)
  
# 代码

###  dfs
```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0]==1) return 0;
        // 定义状态
        vector<vector<long>> dp(m,vector<long>(n,0));  // 要用long  不然会产生数据溢出
        // 第一列
        for (int i=0;i<m;i++)
        {
            if (obstacleGrid[i][0]==1)
            {
                dp[i][0] = 0;
                break;
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        // 第一行
        for (int j=0;j<n;j++)
        {
            if (obstacleGrid[0][j]==1)
            {
                dp[0][j] = 0;
                break;
            }
            else
            {
                dp[0][j] = 1;
            }
        }
        // 状态方程
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                if (obstacleGrid[i][j]==0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```


