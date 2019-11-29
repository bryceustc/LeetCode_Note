# 题目描述: 搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:
```
输入: [1,3,5,6], 5
输出: 2
```

示例 2:
```
输入: [1,3,5,6], 2
输出: 1
```

示例 3:
```
输入: [1,3,5,6], 7
输出: 4
```

示例 4:
```
输入: [1,3,5,6], 0
输出: 0
```
  
# 解题思路:
  
  1). 使用两次二分查找法，理解左侧边界的含义，数组升序排列，返回start就是小于target的数有多少个，也就是target该插入的位置
  
  2). 遍历一遍原数组，若当前数字大于或等于目标值，则返回当前坐标，如果遍历结束了，说明目标值比数组中任何一个数都要大，则返回数组长度n即可

# 时间复杂度：
  O(logn) + O(logn) , O(logn)
  
# 空间复杂度
  O(1)
# 代码

## [C++](./Search-Insert-Position.cpp):
### 方法一：一次二分查（理解左边界含义）
```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int start = 0;
        int end = n;
        while (end>start)
        {
           int mid = start + (end-start)/2;
           if (nums[mid]==target)
              end = mid;
           if (nums[mid]<target)
              start = mid + 1;
           if (nums[mid]>target)
              end = mid;
        }
        return start;
    }
};
```

## 方法二：直接遍历
```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      if (nums.empty()) return 0; 
      int n = nums.size();
      for(int i=0;i<n;i++)
      {
          if(nums[i]>=target)
          {
              return i;
          }
      }
      return n;
    }
};
```



## [Python](LeetCode_Note/python/Search-Insert-Position/Search-Insert-Position.py)
### 方法一：一次二分法
```python
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
```

### 方法二：直接遍历
```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if n==0:
            return 0
        for i in range(n):
            if nums[i]>=target:
                return i
        return n
```

# 参考：
 - [二分查找算法](LeetCode_Note/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/BinarySearch.md)
