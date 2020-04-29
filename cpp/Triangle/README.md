# 题目描述:  三角形最小路径和

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：
```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

# 解题思路:
  dp
  
  1、**定义状态**：dp[i][j] 表示到达 i, j 的最小路径和
  
  2、**状态转移方程**
  
到达[i,j]这个位置有两种方法：

   - 从[i-1,j]位置到达

   - 从[i-1,j-1]位置到达

所以很容易写出**状态转移方程**：
$$
dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + triangle[i][j];
$$

对于首元素与尾元素分别只与一个元素相邻，所以要特殊处理
$$
dp[i][0] = dp[i-1][0] + triangle[i][0];
$$

$$
dp[i][i] = dp[i-1][i-1] + triangle[i][i];
$$

3、**初始状态：**

前两行需要处理

# 时间复杂度：
  O(n^2)
# 空间复杂度
O(n^2)
  
# 代码

### dp
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (triangle.empty()) return 0;
        if (n==1) return triangle[0][0];
        int res = 0;
        // 定义状态dp[i][j]表示，第i行所有元素对应的最小路径和
        vector<vector<int>> dp(n,vector<int>(n,0));
        // 初始状态
        dp[0][0] = triangle[0][0];
        for (int j=0;j<=1;j++)
        {
            dp[1][j] = dp[0][0] + triangle[1][j];
        }
        // 状态转移方程
        for (int i =2;i<n;i++)
        {
            // 首元素与尾元素分别只与一个元素相邻
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            for (int j=1;j<i;j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
        // 结果为最后一行中最小的路径之和
        res = dp[n-1][0];
        for (int j=0;j<n;j++)
        {
            res = min(res, dp[n-1][j]);
        }
        return res;
    }
};
```
#### dp 优化版 其实我们dp时候每次只用到上一层数据,如果我们倒着,从底向上可以优化成O(n)空间的
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (triangle.empty()) return 0;
        vector<int> dp(n,0);
        for (int i=0;i<n;i++)
        {
            dp[i] = triangle[n-1][i];
        }
        for (int i=n-2;i>=0;i--)
        {
            for (int j=0;j<i+1;j++)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
```
#### dp 精简版 O(1) 空间复杂度
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (triangle.empty()) return 0;
        // 自底向上 原数组上修改
        for (int i=n-2;i>=0;--i)
        {
            for (int j=0;j<triangle[i].size();j++)
            {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
```
