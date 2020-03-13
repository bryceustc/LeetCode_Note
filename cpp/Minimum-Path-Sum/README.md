# 题目描述:  最小路径和

给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

**示例 :**
```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```

# 解题思路:
  dp
  
  1、**定义状态**：dp[i][j] 表示到达 i, j 的最小路径和
  
  2、**状态转移方程**
  
  机器人到达[i,j]这个位置有两种方法：

   - 从[i-1,j]位置到达

   - 从[i,j-1]位置到达

所以很容易写出**状态转移方程**：
$$
dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
$$

对于第一行 dp[0][j]，或者第一列 dp[i][0], 由于都是在边界，所以要特殊处理
$$
dp[i][0]=dp[i-1][0]+ grid[i][0];
$$

$$
dp[0][j]=dp[0][j-1]+ grid[0][j];
$$

3、**初始状态：**

i=j=0, dp[0][0] = grid[0][0]

# 时间复杂度：
  O(n)
# 空间复杂度
O(n)
  
# 代码

### dp
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        // 定义状态dp
        vector<vector<int> > dp(m, vector<int>(n,0));

        // 初始状态
        dp[0][0] = grid[0][0];

        // 状态转移方程
        for (int i=1;i<m;i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j=1;j<n;j++)
        {
            dp[0][j] = dp[0][j-1] +  grid[0][j];
        }
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
```
#### dp 精简版 O(1) 空间复杂度
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        // 直接原数组上修改
        for (int i=1;i<m;i++)
        {
            grid[i][0] += grid[i-1][0];
        }
        for (int j=1;j<n;j++)
        {
            grid[0][j] += grid[0][j-1];
        }
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
```
