# 题目描述:  最长上升子序列

给定一个无序的整数数组，找到其中最长上升子序列的长度。

**示例 :**
```
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
```

# 解题思路:
  I. dp
  
  1、**定义状态**：dp[i]表示以nums[i]为结尾的最长上升序列的长度
  
  2、**状态转移方程**
  
在索引 i 之前严格小于 nums[i] 的所有状态中的最大者 +1

0<j<i

所以在$nums[i] > nums[j]$写出状态转移方程：
$$
dp[i]=max(dp[i], dp[j]+1) 
$$

3、**初始状态：**

dp[i] 所有元素置 1，含义是每个元素都至少可以单独成为子序列，此时长度都为 1。

4、**返回值**

返回 dp 列表最大值，即可得到全局最长上升子序列长度

  II. dp

# 时间复杂度：
  1:O(n^2)
# 空间复杂度
  
  1: O(n)
  
  2:O(n)
  
# 代码

### dp
```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return n;
        // 定义状态：dp[i]表示以nums[i]为结尾的最长上升序列的长度
        vector<int> dp(n,1);
        // 初始状态：都为1
        for (int i = 0;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (nums[i]>nums[j])
                {
                    // 状态转移方程
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int res = 0;
        for (int i=0;i<n;i++)
        {
            res = max(res, dp[i]);
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
        // 定义状态 dp[i] 表示区间 [0,i]位置的最长连续上升子序列的长度。
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
        if (n==1) return 1;
        // 定义状态 dp[i] 表示区间 [0,i]位置的最长连续上升子序列的长度。
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
            res = max(res, dp[i]);
        }
        return res;
    }
};
```