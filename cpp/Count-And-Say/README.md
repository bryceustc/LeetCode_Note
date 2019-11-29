# 题目描述: 报数

报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

```
1.     1
2.     11
3.     21
4.     1211
5.     111221
```
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

示例 1:
```
输入: 1
输出: "1"
```

示例 2:
```
输入: 4
输出: "1211"
```
  
# 解题思路:
  
  1). 使用两次二分查找法，理解左侧边界的含义，数组升序排列，返回start就是小于target的数有多少个，也就是target该插入的位置
  
  2). 遍历一遍原数组，若当前数字大于或等于目标值，则返回当前坐标，如果遍历结束了，说明目标值比数组中任何一个数都要大，则返回数组长度n即可

# 时间复杂度：
  方法一:O(logn)
  
  方法二:O(n)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Count-And-Say.cpp):
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



## [Python](LeetCode_Note/python/Count-And-Say/Count-And-Say.py)
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
