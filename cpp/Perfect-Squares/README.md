# 题目描述:  完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

**示例 :**
```
输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.

输入: n = 13
输出: 2
解释: 13 = 4 + 9.
```

# 解题思路:
与零钱兑换那道题比较类似，利用dp来求解
  
**定义状态：**
  - dp[i]表示组成和i的最少完全平方数个数
  
**状态转移方程：**
  - dp[i] = min(dp[i], dp[i-j*j]+1];
  
**初始化：**
  - 初始化长度为n+1的数组dp，每个位置都为0
  
**返回结果：**
  - dp[n]
  
# 时间复杂度：
  O(n ^ 1.5) 
# 空间复杂度
 O(n) 
  
# 代码

### dp
```c++
class Solution {
public:
    int numSquares(int n) {
        // 定义状态，dp[i]表示组成和i的最少完全平方数个数
        vector<int> dp(n+1,0); // dp[0] = 0;
        for (int i=1;i<=n;i++)
        {
            dp[i] = i; // 最坏情况就是i个1组成
            for(int j=1;j*j<=i;j++)
            {
                // 状态转移方程
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
```

