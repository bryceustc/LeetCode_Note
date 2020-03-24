# 题目描述:  打家劫舍 II

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

**示例 :**
```
输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

# 解题思路:
  动态规划：
  
  此题与198题打家劫舍类似，不过房间构成了一个环，我们需要把环拆成两个队列，一个是从0到n-1，另一个是从1到n，然后返回两个结果最大的。用两遍198题的方法就可以。
  
  1. 定义状态：dp[i][j]，表示前i间房子中，状态为j(0/1)的最大金钱数。0为不偷当前房屋，1为偷当前房屋
  
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
        // 定义状态: dp[i][j]，dp[i][j]，表示前i间房子中，状态为j(0/1)的最大金钱数。0为不偷当前房屋，1为偷当前房屋
        vector<vector<int>> dp(n, vector<int> (2,0));
        // 初始状态
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i=1;i<n;i++)
        {
            // 状态转移方程
            // 当前房间不偷，可以是上一间房没有偷，也可以是上一间房偷了今天不能偷
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            // 当前房间要偷，那就是上一间房没有偷
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
### 参考
  - [按摩师](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/The-Masseuse-Lcci/README.md)
  - [打家劫舍II]()
  - [打家劫舍III]()
