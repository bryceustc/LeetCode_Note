# 题目描述:  最后一块石头的重量 II

有一堆石头，每块石头的重量都是正整数。

每一回合，从中任意选出两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

  - 如果 x == y，那么两块石头都会被完全粉碎；
  - 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
  
最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。

# 解题思路:
0-1背包问题

# 时间复杂度：
  1:O(mn)
  
  2:O(n)
# 空间复杂度
  1:O(mn)
  
  2:O(n)
  
# 代码

## C++
### 二维dp数组
```c++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int stone: stones)
        {
            sum+=stone;
        }
        int maxCapcity = sum/2;
        // 定义状态：dp[i][j] 代表前i个石头，背包容量为j的情况下，得到最佳组合的重量
        vector<vector<int>> dp(n+1, vector<int> (maxCapcity+1,0));
        for (int i=1;i<=n;i++)
        {
            for (int j= 1;j<=maxCapcity;j++)
            {
                // 0-1背包的状态转移方程
                if (j>=stones[i-1])
                {
                    dp[i][j]  = max(dp[i-1][j] , dp[i-1][j-stones[i-1]]+stones[i-1]);
                }
                // 第i块石头容量要＜j，不然不取这块石头
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // return sum- dp[n][maxCapcity]  - dp[n][maxCapcity]  // 两堆石头之差
        return sum - 2*dp[n][maxCapcity];
    }
};
```
### 优化为一维dp数组
```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int res = 0;
        // 大顶堆
        priority_queue<int, vector<int>> q;
        for (int stone : stones)
        {
            q.push(stone);
        }
        while(q.size()>1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x!=y)
            {
                int z = y-x;
                q.push(z);
            }
        }
        if (!q.empty()) res = q.top();
        return res;
    }
};
```
