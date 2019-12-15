### Python Solution 1:动态规划
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n==0: 
            return False
        dp=[0 for _ in range(n)]
        for i in range (1,n):
            dp[i] = max(dp[i-1],nums[i-1])-1
            if dp[i]<0:
                return False
        return True

      
      
### Python Solution 2:贪心算法
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        reach = 0
        if n==0: 
            return False
        for i in range (n):
            if  i> reach or reach==n-1:
                break
            reach = max(reach,i+nums[i])
        return reach>=n-1
