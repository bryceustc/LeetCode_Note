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
