### Solution 1：
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
      
      
### Solution 2：
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

      
### Solution 3：
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        #递归终止条件
        if n == 1:
            return nums[0]
        else:
            #递归计算左半边最大子序和
            max_left = self.maxSubArray(nums[0:len(nums) // 2])
            #递归计算右半边最大子序和
            max_right = self.maxSubArray(nums[len(nums) // 2:len(nums)])
        
        #计算中间的最大子序和，从右到左计算左边的最大子序和，从左到右计算右边的最大子序和，再相加
        max_l = nums[len(nums) // 2 - 1]
        tmp = 0
        for i in range(len(nums) // 2 - 1, -1, -1):
            tmp += nums[i]
            max_l = max(tmp, max_l)
        max_r = nums[len(nums) // 2]
        tmp = 0
        for i in range(len(nums) // 2, len(nums)):
            tmp += nums[i]
            max_r = max(tmp, max_r)
        #返回三个中的最大值
        return max(max_right,max_left,max_l+max_r)
    
    
### Solution 4:
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
