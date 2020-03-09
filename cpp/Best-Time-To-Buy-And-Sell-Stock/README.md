# 题目: 买卖股票的最佳时机

## 题目描述：
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

# 解题思路:
  1) 暴力遍历
  
 2) 动态规划思想：
  
   - 记录【今天之前买入的最小值】
   - 计算【今天之前最小值买入，今天卖出的获利】，也即【今天卖出的最大获利】
   - 比较【每天的最大获利】，取最大值即可
# 时间复杂度：
1: O(n^2)

2: O(n)
# 空间复杂度
 O(1)
# 代码

[C++](./Extract_Unique_Integers.cpp)
# C++: 
###  暴力遍历
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (prices[j]>prices[i])
                {
                    res = max(res, prices[j]-prices[i]);
                }
            }
        }
        return res;
    }
};
```

### 动态规划
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

