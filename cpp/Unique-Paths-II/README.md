# 题目描述:  不同路径 II

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

网格中的障碍物和空位置分别用 1 和 0 来表示。

**示例 :**
```
输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

```

# 解题思路:
  1、**定义状态**：dp[i][j] 表示到达 i, j 最多路径
  
  2、**状态转移方程**
  
  没有障碍时，机器人到达[i,j]这个位置有两种方法：

   - 从[i-1,j]位置到达

   - 从[i,j-1]位置到达

所以很容易写出**状态转移方程**：
$$
dp[i][j]=dp[i-1][j]+dp[i][j-1]
$$

有障碍时
$$
dp[i][j] = 0
$$

3、**初始状态：**

grid[0][0] == 1  return 0;

对于第一行 dp[0][j]，或者第一列 dp[i][0], 由于都是在边界，遇到障碍之前为 1，之后不管有无障碍都为0.

# 时间复杂度：
  O(n)
# 空间复杂度
  
  1: O(1)
  
  2:O(n)
  
# 代码

###  dp
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

