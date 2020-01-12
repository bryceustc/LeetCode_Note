### Python Solution 1:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        if (nums[n-1]!=n)
        {
            return n;
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=i)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
### Python Solution 2：
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0;
        n = len(nums)
        x = range(n+1)
        x = list(x)           ### Python3 需要用list转换成数组
        res = sum(x)-sum(nums)
        return res
      
      
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        res = n
        for i in range(n):
            res = res ^ nums[i]
            res = res ^ i
        return res
### Python Solution 3:
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums = sorted(nums)
        n = len(nums)
        if nums[-1] != n:
            return n
        for i in range(0,n):
            if i!=nums[i]:
                return i
