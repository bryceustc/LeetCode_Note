### Python Solution 1: 未通过OJ
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        res = []
        n = len(nums)
        if n==0:
            return
        for i in range(n):
            if nums[i]!=0:
                res.append(nums[i])
        for i in range(n):
            if nums[i]==0:
                res.append(nums[i])
        nums=res
        
        
### Python Solution 2：
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        for i in range(0,n):
            if nums[i]==0:
                for j in range(i+1,n):
                    if nums[j]!=0:
                        temp = nums[j]
                        for k in range (j,i,-1):
                            nums[k] = nums[k-1]
                        nums[i] = temp
                        break


### Python Solution 3: 未通过OJ
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        for i in range(0,n):
                for j in range(n-1,i,-1):
                    if nums[j]!=0 and nums[j-1]==0:
                        temp = nums[j]
                        nums[j] = nums[j-1]
                        nums[j-1] = temp
