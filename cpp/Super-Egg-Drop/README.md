# 题目描述:  鸡蛋掉落

你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。

每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。

你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。

每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。

你的目标是确切地知道 F 的值是多少。

无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

**示例 :**
```
输入：K = 1, N = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
```

# 解题思路:
  动态规划：
  
  1. 定义状态：dp[i][j]，表示前i个预约，状态为j(0/1)的最大预约时间数。0为不接受当前预约，1为接受当前预约
  
  2. 状态转移方程：
  $$
   dp[i][0] = max(dp[i-1][0], dp[i-1][1]);   
   dp[i][1] = dp[i-1][0] + nums[i];
  $$
  
  3. 初始状态：
  ```
  dp[0][0] = 0;  dp[0][1] = nums[0];
  ```
  4. 返回结果：
   ```
   res = max(dp[n-1][0], dp[n-1][1]);
   ```
   5. 考虑状态压缩：
   ```
   int tdp_0 = max(dp_0, dp_1);
   tdp_1 = dp_0 + nums[i];
   dp_0 = tdp_0;
   dp_1 = tdp_1;
   ```
# 时间复杂度：
  O(n)
# 空间复杂度
  1: O(n)
  
  2: O(1)
  
# 代码
### dp
```c++
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        int res = 0;
        // 定义状态: dp[i][j]，表示前i个预约，状态为j(0/1)的最大预约时间数。0为不接受当前预约，1为接受当前预约
        vector<vector<int>> dp(n, vector<int> (2,0));
        // 初始状态
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i=1;i<n;i++)
        {
            // 状态转移方程
            // 今天不接受，可以是昨天也不接受，也可以是昨天接受了今天不接受
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            // 今天接受，那就是昨天不接受
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        // 返回结果
        res = max(dp[n-1][0], dp[n-1][1]);
        return res;
    }
};
```
###  dp考虑状态压缩
```c++
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        int dp_0 = 0;
        int dp_1 = nums[0];
        for (int i=1;i<n;i++)
        {
            int tdp_0 = max(dp_0, dp_1);
            int tdp_1 = dp_0 + nums[i];
            dp_0 = tdp_0;
            dp_1 = tdp_1;
        }
        return max(dp_0, dp_1);
    }
};
```
