

#########Python Solution 1:一次二分法
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if n==0:
            return 0
        start = 0
        end = n
        while end > start:
            mid = start + (end-start)//2
            if nums[mid]<target:
                start=mid+1
            else:
                end = mid
        return start
        
        
#########Python Solution 2：遍历法        
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if n==0:
            return 0
        for i in range(n):
            if nums[i]>=target:
                return i
        return n
