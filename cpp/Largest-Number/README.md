# 题目描述:  最大数

给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

**示例 1:**
```
输入: [10,2]
输出: 210
```

**示例 2:**
```
输入: [3,30,34,5,9]
输出: 9534330
```
**说明:** 
输出结果可能非常大，所以你需要返回一个字符串而不是整数。
  
# 解题思路:
此题与剑指offer第45题类似
这道题给了我们一个数组，让将其拼接成最大的数，那么根据题目中给的例子来看，主要就是要给数组进行排序，但是排序方法不是普通的升序或者降序，因为9要排在最前面，而9既不是数组中最大的也不是最小的，所以要自定义排序方法。如果不参考网友的解法，博主估计是无法想出来的。这种解法对于两个数字a和b来说，如果将其都转为字符串，如果 ab > ba，则a排在前面，比如9和34，由于 934>349，所以9排在前面，再比如说 30 和3，由于 303<330，所以3排在 30 的前面。按照这种规则对原数组进行排序后，将每个数字转化为字符串再连接起来就是最终结果。

 
# 时间复杂度：
  时间复杂度：O(nlgn)
  
  尽管我们在比较函数中做了一些额外的工作，但是这只是一个常数因子。所以总的时间复杂度是由排序决定的，在 C++ 和 Python 中都是 O(nlgn)。
# 空间复杂度
  O(n)
  
  这里，我们使用了 O(n) 的额外空间去保存 nums 的副本。尽管我们就地进行了一些额外的工作，但最后返回的数组需要 O(n) 的空间。因此，需要的额外空间与 nums 大小成线性关系。
# 代码

## [C++](./Largest-Number.cpp):

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
            return res;
      
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


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Largest-Number/Largest-Number.py)
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



