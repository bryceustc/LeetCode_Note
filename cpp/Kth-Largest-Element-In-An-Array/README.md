# 题目描述:  数组中的第K个最大元素

在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

**示例 1:**
```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

**示例 2:**
```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

  
# 解题思路:
此题与剑指offer第40题类似

方法一：sort排序后返回，时间复杂度(nlogn)

方法二：大顶堆和小顶堆 时间复杂度(nlogk) 空间复杂度(logk)

方法三：Partition函数快速选择  时间复杂度(n)

 
# 时间复杂度：
  方法一：O(nlogn) 
  
  方法二：O(nlogk)
  
  方法三：O(n)

# 空间复杂度
方法一：O(1)

方法二：O(logk)

方法三：O(1)
# 代码

## [C++](./Kth-Largest-Element-In-An-Array.cpp):

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


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Kth-Largest-Element-In-An-Array/Kth-Largest-Element-In-An-Array.py)
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



