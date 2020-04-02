# 题目描述:  生命游戏

根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

 - 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
 - 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
 - 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 - 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

# 解题思路:
用dp[i] 来表示组成i块钱，需要最少的硬币数，那么

1. 第j个硬币我可以选择不拿 这个时候， 硬币数 = dp[i]

2. 第j个硬币我可以选择拿 这个时候， 硬币数 = dp[i - coins[j]] + 1

  - 和背包问题不同， 硬币是可以拿任意个

  - 对于每一个 dp[i] 我们都选择遍历一遍 coin， 不断更新 dp[i]

PS：为啥 dp 数组初始化为 amount + 1 呢，因为凑成 amount 金额的硬币数最多只可能等于 amount（全用 1 元面值的硬币），所以初始化为 amount + 1 就相当于初始化为正无穷，便于后续取最小值。


# 时间复杂度：
  O(kn) 子问题总数不会超过金额数 n，即子问题数目为 O(n)。处理一个子问题的时间不变，仍是 O(k)，所以总的时间复杂度是 O(kn)。k 为coins种类数
# 空间复杂度
  O(kn)
  
# 代码

## C++:
###  
```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = -1;
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        int n = dp.size();
        for (int i = 0;i<n;i++)
        {
            for (int coin : coins)
            {
                // 只有i>coin(面值)的时候才有解
                if (i - coin < 0)
                {
                    continue;
                }
                dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        if (dp[amount] == amount+1)
            return -1;
        else
            res = dp[amount];
        return res;
    }
};
```
## 参考
  - [题解讨论](https://leetcode-cn.com/problems/coin-change/solution/dong-tai-gui-hua-suan-fa-si-xiang-by-hikes/)
