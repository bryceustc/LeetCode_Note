# 题目描述:  最大正方形

在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

**示例 :**
```
输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
```

# 解题思路:
  dp
  
  若某格子值为 1 ，则以此为右下角的正方形的、最大边长为：上面的正方形、左面的正方形或左上的正方形中，最小的那个，再加上此格。

# 时间复杂度：
  O(n)
# 空间复杂度
O(n)
  
# 代码

### dp
```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;//正方形的边长
        if (matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        // dp[i][j] 表示以矩阵中第i行j列为右下角构成最大正方形的边长，即matrix[i-1][j-1]
        vector<vector<int>> dp (row+1,vector<int>(col+1,0));
        // 相当于已经预处理新增第一行、第一列均为0
        for (int i=1;i<=row;i++)
        {
            for (int j=1; j<=col;j++)
            {
                if (matrix[i-1][j-1]=='1')
                {
                    // 状态转移方程
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};
```
