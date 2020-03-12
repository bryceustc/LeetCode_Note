# 题目描述:  最长连续递增序列

给定一个未经排序的整数数组，找到最长且连续的的递增序列。

**示例 :**
```
输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
```
**示例 :**
```
输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
```

# 解题思路:
  1. 双指针
  
  2. dp

# 时间复杂度：
  O(n)
# 空间复杂度
  
  1: O(1)
  
  2:O(n)
  
# 代码

### 双指针
```c++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int i=0, j=0;
        int res = 1;
        while (j<n-1)
        {
            if (nums[j+1] > nums[j])
            {
                j++;
                res = max(res, j-i+1);
            }
            else
            {
                j++;
                i = j;
            }
        }
        return res;
    }
};
```
###  dp
```c++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        // 定义状态 dp[i] 表示区间 [0,i][0,i] 位置的最长连续上升子序列的长度。
        vector<int> dp(n,0);
        // 初始化状态
        dp[0]=1;
        int res = 0;
        for (int i=1;i<n;i++)
        {
            // 状态转移方程：1. dp[i] = dp[i-1] + 1   2. dp[i] = 1;
            if (nums[i] >nums[i-1])
            {
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                dp[i] = 1;
            }
        }
        // 结果为dp数组中的最大值
        for (int m: dp)
        {
            res = max(res,m);
        }
        return res;
    }
};
```
### dp 精简版
```c++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        // 定义状态 dp[i] 表示区间 [0,i][0,i] 位置的最长连续上升子序列的长度。
        vector<int> dp(n,0);
        // 初始化状态
        dp[0]=1;
        int res = 0;
        for (int i=1;i<n;i++)
        {
            // 状态转移方程：1. dp[i] = dp[i-1] + 1   2. dp[i] = 1;
            if (nums[i] >nums[i-1])
            {
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                res = max(res,dp[i]);
            }
        }
        return res;
    }
};
```
