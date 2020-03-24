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
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        vector<vector<int>> dp1(n-1, vector<int>(2,0));
        vector<vector<int>> dp2(n, vector<int>(2,0));
        dp1[0][0] = 0; dp1[0][1] = nums[0];
        dp2[1][0] = 0; dp2[1][1] = nums[1];
        for (int i=1;i<n-1;i++)
        {
            dp1[i][0] = max(dp1[i-1][0], dp1[i-1][1]);
            dp1[i][1] = dp1[i-1][0] + nums[i];
        }
        int res1 = max(dp1[n-2][0], dp1[n-2][1]);
        for (int i=2;i<n;i++)
        {
            dp2[i][0] = max(dp2[i-1][0], dp2[i-1][1]);
            dp2[i][1] = dp2[i-1][0] + nums[i];
        }
        int res2 = max(dp2[n-1][0], dp2[n-1][1]);
        return max(res1, res2);
    }
};
```
###  dp简化版
```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        int dp1_0 = 0;
        int dp1_1 = nums[0];
        int dp2_0 = 0;
        int dp2_1 = nums[1];
        for (int i=1;i<n-1;i++)
        {
            int tdp1_0 = max(dp1_0, dp1_1);
            int tdp1_1 = dp1_0 + nums[i];
            dp1_0 = tdp1_0;
            dp1_1 = tdp1_1;
        }
        int res1 = max(dp1_0, dp1_1);
        for (int i=1;i<n-1;i++)
        {
            int tdp2_0 = max(dp2_0, dp2_1);
            int tdp2_1 = dp2_0 + nums[i+1];
            dp2_0 = tdp2_0;
            dp2_1 = tdp2_1;
        }
        int res2 = max(dp2_0, dp2_1);
        return max(res1, res2);
    }
};
```
