# 题目描述:  最大子序和

给定一个整数数组 ``nums`` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。


**示例 :**
```
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

**进阶：**

  如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

  
# 解题思路:
  尝试一：暴力求解
  
  方法二：动态规划，``dp[i]``表示``nums``中以``nums[i]``结尾的最大子序和
# 时间复杂度：
  方法一：O(n<sup>2</sup>)
  
  方法二：O(n)
  
  方法三：O(nlogn)
# 空间复杂度
  方法一: O(1)
  
  方法二：O(n)
  
  方法三：O(1)
  
# 代码

## [C++](./Maximum-Subarray.cpp):

### 方法一： 暴力求解法
```c++
class Solution {
public:
    int maxSubArray(vector<int> &nums){
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int res = INT_MIN;
        // int res = nums[0];
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            int sum = 0;
            for (int j=i;j<n;j++)
            {
                sum+=nums[j];
                res = max(res,sum);
            }
        }
        return res;
    }
};
```

### 方法二：动态规划


#### 空间复杂度O(n)
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int res = nums[0];
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i=1;i<n;i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};
```


#### 空间复杂度O(1)
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int res = nums[0];
        int n = nums.size();
        int sum = 0;
        for (int i=0;i<n;i++)
        {
            if (sum>0)
            {
                sum+=nums[i];
            }
            else
            {
                sum = nums[i];
            }
            res = max(res,sum);
        }
        return res;
    }
};
```


### 方法三： 分治法
```c++
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int res = nums[0];
        int n = nums.size();
        res = maxSubArrayHelper(nums, 0, n - 1);
        return res;
    }

    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftSum = maxSubArrayHelper(nums, left, mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无线循环
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
        int res = max(leftSum, rightSum);
        res = max(res, midSum);
        return res;
    }

    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Maximum-Subarray/Maximum-Subarray.py)
### 方法一： 暴力求解法(未通过OJ，超时)
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        n = len(nums)
        for i in range(n):
            s = 0
            for j in range(i,n):
                s += nums[j]
                res = max(res,s)
        return res
```

### 方法二： 动态规划
#### 空间复杂度O(1)
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        s = 0
        n = len(nums)
        for i in range(n):
            if s>0:
                s+=nums[i]
            else:
                s = nums[i]
            res = max(res,s)
        return res
```

#### 空间复杂度O(n)
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        n = len(nums)
        dp = [0 for _ in range(n)]
        dp[0] = nums[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1]+nums[i],nums[i])
            res = max(res,dp[i])            
        return res
```


### 方法三： 分治法
```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1.0
        i = abs(n)    ### 注意Python负数取余与C++负数取余不一样
        while i!=0:
            if i%2!=0:
                res*=x
            x*=x
            i=i//2
        if n<0:
            res = 1/res
        return res
```

