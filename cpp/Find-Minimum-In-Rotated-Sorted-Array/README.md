# 题目描述:  寻找旋转排序数组中的最小值

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

**示例 1:**
```
输入: [3,4,5,1,2]
输出: 1
```

**示例 2:**
```
输入: [4,5,6,7,0,1,2]
输出: 0
```

  
# 解题思路:
此题与剑指offer第十一题相似

方法一：直接暴力遍历数组所有元素，寻找最小元素，时间复杂度为O(n)

方法二：使用二分查找，如果中间元素大于等于首元素，``start=mid+1``，时间复杂度为O(logn)

方法三：利用STL容器vector里边sort函数，时间复杂度为O(n)
 
# 时间复杂度：
  方法一： O(n)
  
  方法二： O(logn)
  
  方法三： O(n) 
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Find-Minimum-In-Rotated-Sorted-Array.cpp):

###  方法一： 暴力遍历法
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();     
        int res = nums[0];
        for (int i=1;i<n;i++)
        {
            if (res>nums[i])
                res = nums[i];
        }
        return res;
    }
};
```

###  方法二： 二分查找法
```c++
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty()) return 0;
        int n = numbers.size();
        int start = 0;
        int end = n-1;
        while(end>start)
        {
            int mid = start + (end-start)/2;
            if (numbers[mid] > numbers[end])
            {
                start = mid+1;
            }
            else if (numbers[mid]< numbers[end])
            {
                end = mid;
            }
            else
                end--;
        }
        return numbers[start];
    }
};
```
###  方法三： sort排序后 返回
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        sort(nums.begin(),nums.end());
        res =nums[0];
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Find-Minimum-In-Rotated-Sorted-Array/Find-Minimum-In-Rotated-Sorted-Array.py)
###  方法一：暴力遍历法
```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        for i in range (n):
            if res >nums[i]:
                res = nums[i]
        return res
```
### 方法二 ：二分查找
```python
# -*- coding:utf-8 -*-
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        start = 0
        end = n-1
        while end>=start:
            mid = start+(end-start)//2
            if nums[mid]>=res:
                start=mid+1
            if nums[mid]<res:
                end = mid-1
            res = min(res,nums[mid])
        return res
```

### 方法三 ：sort排序后返回
```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return 0
        res = nums[0]
        for i in range (n):
            if res >nums[i]:
                res = nums[i]
        return res
```

# 参考

  -  [旋转数组的最小数字](https://github.com/bryceustc/CodingInterviews/blob/master/MinNumberInRotatedArray/README.md)
  -  [二分查找算法](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/BinarySearch.md)


