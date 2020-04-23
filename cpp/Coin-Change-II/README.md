# 题目描述:  零钱兑换II

给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

示例：
```
输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

示例：
```
输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
```


# 解题思路:
  动态规划
  
  1、**定义状态**：
  
  dp[i][j] 表示使用硬币的**前i个**可以凑成金额j的个数
  
  2、**状态转移方程**：
  
  针对第i个硬币，对应coins数组中的coins[i-1]，可以选择拿或者不拿
  
  当j>=coins[i-1]时:
  $$
  dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
  $$
  
  否则：
  $$
  dp[i][j] = dp[i-1][j];
  $$
  
  3、**初始状态：**
  
  dp数组初始化为 (coins.size()+1) * (amount+1), dp[i][0] = 1，因为组成金额0的方式就一种都不取
  
  4、**返回结果：**
  
  返回dp[n][amount]
  
  5、**考虑状态压缩：**
  
  只用一维数组，重新定义状态，dp[i]表示的是使用第k个硬币时能凑的组合数


# 时间复杂度：
  O(kn) 子问题总数不会超过金额数 n，即子问题数目为 O(n)。处理一个子问题的时间不变，仍是 O(k)，所以总的时间复杂度是 O(kn)。k 为coins种类数
# 空间复杂度
  1. O(kn)
  
  2. O(n)
  
# 代码
###  动态规划
```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for (int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for (int i=1;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if (j>=coins[i-1])
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};
```
### 动态规划优化 
```c++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 对于硬币从0到k，我们必须使用第k个硬币，当前金额的组合数。
        // 定义状态：dp[i]表示的是对于第k个硬币能凑的组合数
        vector<int> dp (amount+1,0);
        // 初始化
        dp[0] = 1;
        for (int coin:coins)
        {
            // 记录每添加一种面额的零钱，总金额i的变化
            for (int i=1;i<=amount;i++)
            {
                if (i>=coin)
                {
                    // 在上一种零钱状态的基础上增大
                    // coin=1: dp[1]=1,dp[2]=1,dp[3]=1,dp[4]=1,dp[5]=1
                    // coin=2: dp[1]=1,dp[2]=dp[2]+dp[0]=2,dp[3]=2,dp[4]=3,dp[5]=3
                    // coin=5: dp[1]=1,dp[2]=2,dp[3]=2,dp[4]=3,dp[5]=4
                    dp[i]+=dp[i-coin];
                }
            }
        }
        return dp[amount];
    }
};
```
## 参考
  - [题解讨论](https://leetcode-cn.com/problems/coin-change-2/solution/ling-qian-dui-huan-iihe-pa-lou-ti-wen-ti-dao-di-yo/)
