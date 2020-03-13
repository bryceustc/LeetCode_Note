# 题目描述:  不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

**示例 :**
```
输入: m = 7, n = 3
输出: 28
```

# 解题思路:
  1、**定义状态**：dp[i][j] 表示到达 i, j 最多路径
  
  2、**状态转移方程**
  
  机器人到达[i,j]这个位置有两种方法：

   - 从[i-1,j]位置到达

   - 从[i,j-1]位置到达

所以很容易写出**状态转移方程**：
$$
dp[i][j]=dp[i-1][j]+dp[i][j-1]
$$

3、**初始状态：**

对于第一行 dp[0][j]，或者第一列 dp[i][0], 由于都是在边界，所以只能为 1.

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
    int uniquePaths(int m, int n) {
        if (m<=0 || m>100 || n<=0 || n>100) return 0;
        // 定义状态
        vector<vector<int>> dp (m,vector<int>(n));
        // 初始状态 第一列只能向下走
        for (int i=0;i<m;i++)
        {
            dp[i][0] = 1;
        }
        // 初始状态 第一行只能向右走
        for (int j=0;j<n;j++)
        {
            dp[0][j] = 1;
        }
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                // 状态转移方程
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```
