# 题目描述:  多数元素

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ``⌊ n/2 ⌋ ``的元素。

**示例 1:**
```
输入: [3,2,3]
输出: 3
```

**示例 2:**
```
输入: [2,2,1,1,1,2,2]
输出: 2
```

  
# 解题思路:
此题与剑指offer第39题类似，但比39题简单

方法一：暴力遍历

方法二：哈希表

方法三：摩尔投票

方法四：排序后，返回数组中间的数

 
# 时间复杂度：
  方法一：O(n<sup>2) 
  
  方法二：O(n)
  
  方法三：O(n)
  
  方法四：O(nlogn)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Majority-Element.cpp):

###  方法一： 暴力法
```c++
class Solution{
    public:
        int majorityElement(vector<int>&nums)
        {
            int res = 0 ;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            for (int i=0;i<n;i++)
            {
                int count = 0;
                for (auto num : nums)
                {
                    if (nums[i] == num)
                    {
                        count+=1;
                        if (count > half)
                        {
                            res = num;
                        }
                    }
                }
            }
            return res;          
        }
};
```

###  方法二： 哈希表
```c++
class Solution{
    public:
        int majorityElement(vector<int>&nums)
        {
            int res =0;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            unordered_map<int,int> record;
            for (auto num:nums)
            {
                record[num]++;
                if(record[num]>half)
                {
                    res = num;
                }
            }     
      
```

###  方法三： 摩尔投票
```c++
class Solution{
    public:
        int majorityElement(vector<int>&nums)
        {
            int res = 0 ;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            for (int i=0;i<n;i++)
            {
                int count = 0;
                for (auto num : nums)
                {
                    if (nums[i] == num)
                    {
                        count+=1;
                        if (count > half)
                        {
                            res = num;
                        }
                    }
                }
            }
            return res;          
        }
};
```


###  方法四：排序后返回 
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        if (nums.empty()) return res;
        int n = nums.size();
        int half = n/2;
        sort(nums.begin(),nums.end());
        res = nums[half];
        return res;      
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Majority-Element/Majority-Element.py)
###  方法一：暴力法
```python
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
```
### 方法二 ： 摩尔投票法
```python
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
```

### 方法三 ： 排序法
```python
class Solution:
    def majorityElement(self, nums):
        # write code here
        res = 0
        n = len(nums)
        nums=sorted(nums)
        res = nums[n//2]
        return res
```



# 参考
  - [剑指offer第39题-数组中出现次数超过一半的数字](https://github.com/bryceustc/CodingInterviews/blob/master/MoreThanHalfNumber/README.md)


