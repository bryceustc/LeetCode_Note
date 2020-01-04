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
  方法一：暴力求解，枚举每一个子序列的大小，记录下最大的和返回。
  
  方法二：动态规划，在整个数组或在固定大小的滑动窗口中找到总和或最大值或最小值的问题可以通过动态规划（dp）在线性时间内解决。构建一个动态数组vector<int> dp(n),dp[i]表示nums中以nums[i]结尾的最大子序和，dp[i] = max(dp[i-1]+nums[i],nums[i]),dp[i]要么是当前数字，要么是与前面的最大子序和的和。时间复杂度:O(n),空间复杂度O(n)(空间复杂度可优化为O(1))
  
  方法三：贪心算法，从左向右迭代，一个个数字加过去，如果sum<0,重新开始寻找子序列。时间复杂度O(n),空间复杂度O(1).
  
  方法四：分治算法，将一个问题拆分成多个相似的小问题，并对其分别求解，如果拆出的问题依然复杂，就通过递归调用再次将子问题拆分，直到拆出的方法可以以简单方式求得解，最后合并多个小问题的解，就是原问题的结果。
# 时间复杂度：
  方法一：O(n<sup>2</sup>)
  
  方法二：O(n)
  
  方法三：O(n)
  
  方法四：O(nlogn)
# 空间复杂度
  方法一: O(1)
  
  方法二：O(n)/O(1)
  
  方法三：O(1)
  
  方法四：O(logn) 递归时栈使用的空间
  
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

### 方法三： 贪心算法
```c++
class Solution {
public:
    int maxSubArray(vector<int> nums) {
        int res = nums[0];
        int n = nums.size();
        int sum = 0;
        for (int i=0;i<n;i++)
        {
            if (sum > 0)
                sum+=nums[i];
            else
                sum = nums[i];
            res = max(res,sum);
        }
        return res;
    }
};
```




### 方法四： 分治法
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = nums[0];
        int n = nums.size();
        res = maxSubArrayHelper(nums,0,n-1);
        return res;
    }
    
    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right)/2;
        int leftSum = maxSubArrayHelper(nums,left,mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无限循环
        int rightSum = maxSubArrayHelper(nums,mid+1,right);
        int midSum = findMaxCrossingSubarray(nums,left,mid,right);
        int res = max(leftSum,rightSum);
        res = max(res,midSum);
        return res;
    }

    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = nums[mid];
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        int rightSum = nums[mid+1];
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


### 方法三：贪心算法
```python
class Solution:
    def maxSubArray(self, nums):
        # write code here
        res = nums[0]
        n = len(nums)
        sum_num = 0
        for num in nums:
            if sum_num>0:
                sum_num+=num
            else:
                sum_num = num
            res = max(res,sum_num)            
        return res
```



### 方法四： 分治法
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        n = len(nums)
        res = self.maxSubArrayHelper(nums,0,n-1)       
        return res
    def maxSubArrayHelper(self,nums,left,right):
        if left==right:
            return nums[left]
        mid = (left+right)//2
        leftSum = self.maxSubArrayHelper(nums,left,mid)
        rightSum = self.maxSubArrayHelper(nums,mid+1,right)
        midSum = self.maxCrossingSubArray(nums,left,mid,right)
        res = max(leftSum,midSum,rightSum)
        return res
    def maxCrossingSubArray(self,nums,left,mid,right):
        leftBoaderSum = nums[mid]
        cur_sum = 0
        for i in range(mid,left-1,-1):
            cur_sum+=nums[i]
            leftBoaderSum = max(leftBoaderSum,cur_sum)
        rightBoaderSum = nums[mid+1]
        cur_sum = 0
        for i in range(mid+1,right+1):
            cur_sum+=nums[i]
            rightBoaderSum = max(rightBoaderSum,cur_sum)
        return leftBoaderSum + rightBoaderSum
```
# 参考：
   - [剑指offer-42连续子数组的最大和](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Maximum-Subarray/README.md)
   - [五大常用算法之一：分治算法](https://www.cnblogs.com/steven_oyj/archive/2010/05/22/1741370.html) 
   - [五大常用算法之二：动态规划算法](https://www.cnblogs.com/steven_oyj/archive/2010/05/22/1741374.html) 
   - [五大常用算法之三：贪心算法](https://www.cnblogs.com/steven_oyj/archive/2010/05/22/1741375.html)
   - [最大子序和](https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-cshi-xian-si-chong-jie-fa-bao-li-f/)
