# 动态规划：买卖股票的最佳时机系列问题

这是一套经典的动态规划题目，题目主干都是给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格，在不同的情况下求在什么时候买卖以获取最大利润。

  - 121题是只能买卖一次的情况下求最大利润；
  - 122题可以买卖任意多次；
  - 188题是前面三题的泛化版本，给定参数k，求买卖k次情况下的最大利润；
  - 309题是在122题买卖任意多次的基础上加上冷冻期即T+1才能卖出。

其中买卖k次的188题是标准的三维动态规划题，用解这题的通用方可以稍加改造就能解决前三题，当然前三题也有单独的特定简单解法，这里为了练习还是重点看动态规划的解决方法。

在188题的基础上可以再变形出更多题目，比如现在这些题都是最多只能持有1股，如果可以持有n股（每天只能买入或卖出1股），也能用这个188题的三维DP通解来解决。

##  121. 买卖股票的最佳时机

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

**示例1：**
 ```
 输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 ```

**示例2：**
 ```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 ```
## 解：
### 第一种方法：由于一次交易操作，可以通过记录最小价格，计算最大利润的方式，空间换时间，时间复杂度O(n)
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;
        int res = 0;
        int min_price = prices[0];
        for (int i=0;i<n;i++)
        {
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return res;
    }
};
```
### 第二种方法：DP动态规划，与下面122题相比，由于只能一次交易操作，第i天的状态就不止“买入”和“卖出”两种状态，而是“不操作”、“买入”、“卖出”三种状态。
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;
        vector<vector<int>> dp (n, vector<int> (3,0));
        int res = 0;
        // 状态 dp[i][j] 表示：在索引为 i 的这一天，用户手上状态为 j 所获得的最大利润。

        // 0：未持有
        // 1：持有
        // 2：卖出未持有

        dp[0][0] = 0;  
        dp[0][1] = -prices[0]; 
        dp[0][2] = 0;  

        // 状态转移方程：
        // dp[i][0] 永远等于 dp[i-1][0]
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]) 今天持有股票，可以昨天持有rest下来，也可以是昨天没有，今天买了股票
        // dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]) 今天因为未持有股票，可以是昨天早就卖出了，也可以是昨天持有今天卖出

        for (int i=1;i<n;i++)
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); 
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        }
        res = max(dp[n-1][0], dp[n-1][2]);
        return res;
    }
};
```

##  122. 买卖股票的最佳时机 II

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

**示例1：**
 ```
 输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 ```

**示例2：**
 ```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 ```
## 解：
### 第一种方法：贪心算法，一次遍历，只要今天价格小于明天价格就在今天买入然后明天卖出，时间复杂度O(n)
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;
        int res = 0;
        int min_price = prices[0];
        for (int i=0;i<n;i++)
        {
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return res;
    }
};
```
### 第二种方法：标准二维DP动态规划，第i天只有两种状态，不持有或持有股票，当天不持有股票的状态可能来自昨天卖出或者昨天也不持有，同理，当天持有股票的状态可能来自昨天买入或者昨天也持有中，取最后一天的不持有股票状态就是问题的解
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;
        vector<vector<int>> dp (n, vector<int> (2,0));
        dp[0][0] = 0; // 不持有股票，持有现金
        dp[0][1] = -prices[0]; // 持有股票
        for (int i=1;i<n;i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};
```

##  122. 买卖股票的最佳时机 II

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

**示例1：**
 ```
 输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 ```

**示例2：**
 ```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 ```
## 解：
### 第一种方法：贪心算法，一次遍历，只要今天价格小于明天价格就在今天买入然后明天卖出，时间复杂度O(n)
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;
        int res = 0;
        int min_price = prices[0];
        for (int i=0;i<n;i++)
        {
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return res;
    }
};
```
### 第二种方法：标准二维DP动态规划，第i天只有两种状态，不持有或持有股票，当天不持有股票的状态可能来自昨天卖出或者昨天也不持有，同理，当天持有股票的状态可能来自昨天买入或者昨天也持有中，取最后一天的不持有股票状态就是问题的解
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;
        vector<vector<int>> dp (n, vector<int> (2,0));
        dp[0][0] = 0; // 不持有股票，持有现金
        dp[0][1] = -prices[0]; // 持有股票
        for (int i=1;i<n;i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};
```



## 参考
  - [121-买卖股票的最佳时机](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Best-Time-To-Buy-And-Sell-Stock/README.md)
  - [122-买卖股票的最佳时机 II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Best-Time-To-Buy-And-Sell-Stock-II/README.md)
  - [121-买卖股票的最佳时机](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Best-Time-To-Buy-And-Sell-Stock/README.md)
  - [121-买卖股票的最佳时机](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Best-Time-To-Buy-And-Sell-Stock/README.md)
  - [121-买卖股票的最佳时机](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Best-Time-To-Buy-And-Sell-Stock/README.md)
