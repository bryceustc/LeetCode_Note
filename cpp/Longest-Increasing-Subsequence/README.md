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

0<j<i时：

所以在$nums[i] > nums[j]$时，nums[i] 可以接在 nums[j]之后（此题要求严格递增），此情况下最长上升子序列长度为 dp[j]+1。写出状态转移方程：
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
### dp 二分法优化
```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        vector<int> tail;
        tail.push_back(nums[0]);
        // tail 结尾的那个索引
        int end = 0;

        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] > tail[end]) 
            {
                tail.push_back(nums[i]);
                end++;
            } 
            else 
            {
                int left = 0;
                int right = end-1;
                while (left <= right) 
                {
                    int mid = (left + right) >> 1;
                    cout << mid << endl;
                    if (tail[mid] < nums[i]) 
                    {
                        left = mid + 1;
                    } 
                    else 
                    {
                        right = mid-1;
                    }
                }
                tail[left] = nums[i];
            }
        }
        return end + 1;
    }
};
```
