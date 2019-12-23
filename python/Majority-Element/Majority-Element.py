## Pyhton Solution 1:

class Solution:
    def majorityElement(self, nums):
        # write code here
        res = 0
        n = len(nums)
        half = n//2
        if n==0:
            return res
        for i in range(n):
            cnt = 0
            for num in nums:
                if nums[i] == num:
                    cnt+=1
            if cnt > half:
                res = nums[i]
        return res

      ## Python Solution 2:
      
      class Solution:
    def majorityElement(self, nums):
        # write code here
        res = nums[0]
        cnt = 0
        n = len(nums)
        half = n//2
        if n==0:
            return 0
        for i in range(1,n):
            if cnt == 0:
                res = nums[i]
            if res == nums[i]:
                cnt+=1
            else:
                cnt-=1
        m = 0
        for num in nums:
            if (res == num):
                m+=1
        if m<=half:
            res = 0
        return res
      
      
      ## Python Solution 3:
      class Solution:
    def majorityElement(self, nums):
        # write code here
        res = 0
        n = len(nums)
        nums=sorted(nums)
        res = nums[n//2]
        return res
