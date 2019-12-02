# 题目描述: 缺失的第一个正数

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

**示例 1:**
```
输入: [1,2,0]
输出: 3
```

**示例 2:**
```
输入: [3,4,-1,1]
输出: 2
```

**示例 3:**
```
输入: [7,8,9,11,12]
输出: 1
```

**说明：**

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
  
# 解题思路:
  
  

# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./First-Missing-Positive.cpp):
### 方法一： DFS递归法
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> record (nums.begin(),nums.end());
        int res = 1;
        int n = nums.size();
        for (int i = 0;i<n;i++)
        {
            if (record.find(res)==record.end()) return res;  // c++ 哈希表中find 找到返回迭代器,与count用法类似，count统计次数，找到返回1，
            // if(record.count(res)==0) return res;
            res++;
        }
        return res;
    }
};
```
### 方法二： 交换位置法（与剑指Offer中的数组中重复的数字方法类似）
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            while(nums[i]<=n && nums[i]>0 && nums[i]!=nums[nums[i]-1])
            {
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
                // swap(nums[i],nums[nums[i]-1]);
            }
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=i+1)
              return i+1;
        }
        return n+1;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/First-Missing-Positive/First-Missing-Positive.py)
### 方法一： DFS递归法
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while nums[i]<=n and nums[i]>0 and nums[i]!=nums[nums[i]-1]:
                temp = nums[i]
                nums[i] = nums[temp-1]
                nums[temp-1] = temp
        for i in range(n):
            if nums[i]!=i+1:
                return i+1
        return n+1
```

### 方法二：交换位置法
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while nums[i]<=n and nums[i]>0 and nums[i]!=nums[nums[i]-1]:
                temp = nums[i]
                nums[i] = nums[temp-1]
                nums[temp-1] = temp
        for i in range(n):
            if nums[i]!=i+1:
                return i+1
        return n+1
```
# 参考
  - [C++中map，hash_map,unordered_map,unordered_set区别与联系](https://blog.csdn.net/u013195320/article/details/23046305)
  - [数组中重复的数字](https://github.com/bryceustc/CodingInterviews/blob/master/DuplicationInArray/README.md)
