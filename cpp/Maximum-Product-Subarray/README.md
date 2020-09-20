### 题目描述：乘积最大子数组

给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

示例1：
```
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```

动态规划

代码
```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2,0));
        dp[0][0] = nums[0]; // dp[i][0] 表示以nums[i] 结尾的乘积的最小值
        dp[0][1] = nums[0]; // dp[i][1] 表示以nums[i] 结尾的乘积的最大值
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] >= 0) {
                dp[i][0] = min(nums[i], dp[i-1][0] * nums[i]);
                dp[i][1] = max(nums[i], dp[i-1][1] * nums[i]);
            } else {
                dp[i][0] = min(nums[i], dp[i-1][1] * nums[i]);
                dp[i][1] = max(nums[i], dp[i-1][0] * nums[i]);
            }
            res = max(res, dp[i][1]);
        }
        return res;
    }
};
```
