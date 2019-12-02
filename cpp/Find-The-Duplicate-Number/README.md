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
  
# 解题思路:

  这道题让我们找缺失的首个正数，由于限定了 O(n) 的时间，所以一般的排序方法都不能用，不考虑空间复杂度的话，这个思路很简单，利用哈希表求解，把所有的数都存入 HashSet 中，然后循环从1开始递增找数字，哪个数字找不到就返回哪个数字，如果一直找到了最大的数字（这里是 nums 数组的长度），则加1后返回结果 res。
  
  但是利用哈希表的解法不是 O(1) 的空间复杂度，所以需要另想一种解法，既然不能建立新的数组，那么只能覆盖原有数组，思路是把1放在数组第一个位置 ``nums[0]``，2放在第二个位置 ``nums[1]``，即需要把 ``nums[i]`` 放在 ``nums[nums[i] - 1]``上，遍历整个数组，如果 ``nums[i] != i + 1``, 而 ``nums[i]`` 为整数且不大于n，另外 ``nums[i]`` 不等于 ``nums[nums[i] - 1]`` 的话，将两者位置调换，如果不满足上述条件直接跳过，最后再遍历一遍数组，如果对应位置上的数不正确则返回正确的数，这个思路与剑指Offer中的第三题**数组中重复的数字**方法类似
  

# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Trapping-Rain-Water.cpp):
### 方法一： HashSet法
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


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Trapping-Rain-Water/Trapping-Rain-Water.py)
### 方法一： HashSet法
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n =len(nums)
        res = 1
        record = {}
        for index, num in enumerate (nums):
            record[num] = index
        for i in range (n):
            if res not in record:
                return res
            else:
                res+=1
        return res
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
