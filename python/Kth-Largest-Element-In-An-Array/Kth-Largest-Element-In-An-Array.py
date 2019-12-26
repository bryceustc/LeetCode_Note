## Python Solution 1:
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        res = 0
        n = len(nums)
        if n==0 or k>n:
            return res
        nums = sorted(nums)
        res = nums[n-k]
        return res

      
 ### Python Solution 2:
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return heapq.nlargest(k, nums)[-1]
      
      
      
      
 ### Python Solution 3:
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        res = 0
        n = len(nums)
        if n==0 or k>n:
            return 0
        start = 0
        end = n-1
        index = self.partition(nums,start,end)
        while index != n-k:
            if index > n-k:
                end = index - 1
                index = self.partition(nums,start,end)
            else:
                start = index + 1
                index = self.partition(nums,start,end)
        res = nums[n-k]
        return res

    def partition (self,nums: List[int],start:int,end:int) -> int:
        index = random.randint(start, end)
        pivot = nums[index]
        nums[index],nums[start] = nums[start],nums[index]    ##基准值放在数组开始
        pos = start
        for i in range (start+1,end+1):
            if nums[i]<pivot:
                pos+=1
                if i!=pos:
                    nums[pos],nums[i] = nums[i],nums[pos]
        nums[pos],nums[start] = nums[start],nums[pos]
        return pos
    
    # def partition (self,nums: List[int],start:int,end:int) -> int:
    #     index = random.randint(start, end)
    #     pivot = nums[index]
    #     nums[start],nums[index] = nums[index],nums[start]
    #     while start<end:
    #         while start<end and nums[end]>=pivot:
    #             end-=1
    #         nums[start] = nums[end]
    #         while start<end and nums[start]<pivot:
    #             start+=1
    #         nums[end] = nums[start]
    #     nums[start] = pivot
    #     return start
