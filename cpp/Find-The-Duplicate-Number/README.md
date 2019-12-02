# 题目描述: 寻找重复数

给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

**示例1 :**
```
输入: [1,3,4,2,2]
输出: 2
```

**示例2 :**
```
输入: [3,1,3,4,2]
输出: 3
```

**说明：**

1. **不能**更改原数组（假设数组是只读的）。
2. 只能使用额外的 O(1) 的空间。
3. 时间复杂度小于 O(n<sup>2) 。
4. 数组中只有一个重复的数字，但它可能不止重复出现一次。
  
# 解题思路:

  1). 把输入的数组进行排序，排序后再判断有无重复数字，时间复杂度为O(nlogn)，不满足不修改原数组题目要求

  2). 使用哈希表来解决，时间复杂度为O(n)，但空间复杂度也为O(n),空间复杂度不满足题目要求

  3). 交换位置重排法，把每个数字放回对应位置的方法。如果出现一个数字无法放回（所在位置已经是对应数字了），那么说明该数字重复，时间复杂度为O(n)，空间复杂度为O(1)

  4). 使用二分的思想来做，二分基数组，但这种方法不能找出所有重复的数字，时间复杂度为O(nlogn)，空间复杂度为O(1)，相当于用时间换取空间
  
  此题与剑指Offer中的第三题**数组中重复的数字**方法类似
  

# 时间复杂度：
  小于O(n<sup>2)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Trapping-Rain-Water.cpp):
### 方法一： 排序之后直接查找法（时间复杂度为O(nlogn)，不满足不修改原数组题目要求）
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(),nums.end());
        for (int i=1;i<n;i++)
        {
            if (nums[i]==nums[i-1])
                res =nums[i];
                break;
        }
        return res;
    }
};
```
### 方法二： 哈希表法（时间复杂度为O(n)，但空间复杂度也为O(n),空间复杂度不满足题目要求）
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        unordered<int,int> record;
        for (auto  num : nums)
        {
            record[num]++;
            if (record[num]>1)
                res = num;
                break;
        }
        return res;
    }
};
```

### 方法三： 二分法查找（时间复杂度为O(nlogn)，空间复杂度为O(1)）
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        int n = nums.size()-1;
        int start = 1;
        int end = n;
        while(end>start)
        {
            int mid = start + (end-start)/2;
            int k =0;
            for(int i=0;i<n+1;i++)
            {
                if (nums[i]>=start && nums[i]<=mid)
                {
                    k++;
                }
                // for (auto num : nums)
                // {
                //    if (num>=start && num<=mid)
                //          k++;
                // }
            }
              if (k>mid-start+1)
                  end = mid;
              else
                  start = mid +1;
        }
        return start;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Trapping-Rain-Water/Trapping-Rain-Water.py)
### 方法一： 排序之后直接查找法
```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        nums = sorted(nums)
        for i in range (1,n):
            if nums[i]==nums[i-1]:
                res = nums[i]
                break
        return res        
```

### 方法二：哈希表法
```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        dic = {}
        res = 0
        for index, num in enumerate(nums):
            if num in dic:
                res = num
            else:
                dic[num] = index
        return res
```
### 方法三：二分法
```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
         n = len(nums)-1
         start = 1
         end = n
         while end>start:
            mid = start + (end-start)//2
            k = 0
            for num in nums:
                if num>=start and num<=mid:
                    k+=1
            if k > mid-start+1:
                end = mid
            else:
                start = mid + 1
         return start                
```

# 参考
  - [数组中重复的数字](https://github.com/bryceustc/CodingInterviews/blob/master/DuplicationInArray/README.md)
