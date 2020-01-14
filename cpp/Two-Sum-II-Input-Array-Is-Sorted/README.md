# 题目描述:  两数之和 II - 输入有序数组

给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

**说明：**
  - 返回的下标值（index1 和 index2）不是从零开始的。
  - 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
    

**示例 1:**
```
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
```
  
# 解题思路:
此题与剑指offer第57题题目一类似

方法一：暴力遍历

方法二：哈希表

方法三：双指针

 
# 时间复杂度：
  方法一：O(n<sup>2) 
  
  方法二：O(n)
  
  方法三：O(n)
# 空间复杂度
  方法一：O(1)
  
  方法二：O(n)
  
  方法三：O(1)
  
# 代码

## [C++](./Two-Sum-II-Input-Array-Is-Sorted.cpp):

###  方法一： 暴力法
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res (2,0);
        if (numbers.empty())
            return res;
        int n = numbers.size();
        for (int i=0;i<n;i++)
        {
            for (int j = i+1; j<n;j++)
            {
                if (numbers[i]+numbers[j]==target)
                {
                    res[0] = numbers[i];
                    res[1] = numbers[j];
                    break;
                }
            }
        }
        return res;
    }
};
```

###  方法二： 哈希表
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res (2,0);
        if (numbers.empty())
            return res;
        int n = numbers.size();
        unordered_map<int,int> record;
        for (int i=0;i<n;i++)
        {
            int complement = target -numbers[i];
            if (record.find(complement)!=record.end())
            {
                res[0] = complement;
                res[1] = nums[i];
                break;
            }
            record[numbers[i]] = i;
        }
        return res;
    }
};
```

###  方法三：双指针
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res (2,0);
        if (nums.empty())
            return res;
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while (right>left)
        {
            if (nums[left]+nums[right]==target)
            {
                res[0] = nums[left];
                res[1] = nums[right];
                break;
            }
            if (nums[left]+nums[right]>target)
            {
                right--;
            }
            if (nums[left]+nums[right]<target)
            {
                left++;
            }
        }
        return res;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Two-Sum-II-Input-Array-Is-Sorted/Two-Sum-II-Input-Array-Is-Sorted.py)
###  方法一：暴力法
```python
class Solution:
    def  twoSum(self, nums, target):
        # write code here
        res = []
        n = len(nums)
        if n==0:
            return res
        for i in range(n):
            for j in range(i+1,n):
                if nums[i]+nums[j]==target:
                    res.append(nums[i])
                    res.append(nums[j])
                    return res
        return res
```
### 方法二 ：哈希表
```python
class Solution:
    def twoSum(self, nums, target):
        # write code here
        res = []
        record = {}
        n = len(nums)
        if n==0:
            return res
        for index,num in enumerate (nums):
            complement = target - num
            if complement in record:
                res.append(complement)
                res.append(num)
                return res
            record[num] = index
        return res
```

### 方法三 ： 双指针
```python
class Solution:
    def twoSum(self, nums, target):
        # write code here
        res = []
        n = len(nums)
        left = 0
        right = n-1
        while right>left:
            if nums[left]+nums[right]==target:
                res.append(nums[left])
                res.append(nums[right])
                return res
            if nums[left]+nums[right]>target:
                right-=1
            else:
                left+=1
        return res
```



# 参考
  - [剑指offer第57题-和为s的两个数字](https://github.com/bryceustc/CodingInterviews/blob/master/TwoNumbersWithSum/README.md)
