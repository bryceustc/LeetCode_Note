# 题目描述:  只出现一次的数字

给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

**说明** 
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例 1:**
```
输入: [3,0,1]
输出: 2
```
**示例 2:**
```
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
```
  
# 解题思路:

方法一：利用哈希表来做，``unordered_map<int,int> map``,``map[nums[i]]==1``。

方法二：数学方法
 
# 时间复杂度：
  方法一： O(n)
  
  方法二： O(n) 
# 空间复杂度
  方法一：O(n)
  
  方法二：O(1)
  
# 代码

## [C++](./Single-Number.cpp):

###  方法一： 哈希表(unordered_map)  基于哈希表 ，map基于红黑二叉树
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res =0;
        int n = nums.size();
        unordered_map<int,int> map;
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int i=0;i<=n;i++)
        {
            if (map[i] == 0)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
```
###  方法二： 数学方法(0-n相加再减去nums数组所有元素之和)
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res =0;
        int n = nums.size();
        int sum_num = 0;
        int Sum = 0;
        for (int i=0;i<n;i++)
        {
            sum_num+=nums[i];
        }
        for (int i=0;i<=n;i++)
        {
            Sum += i;
        }
        res = Sum - sum_num;
        return res;
    }
};
```

### 方法二： 数学方法(异或)(重要)
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++)
        {
            res ^= nums[i];
            res ^= i;
            // 异或满足交换律，i和nums[i]是肯定有重复的，剩下的只有一个那就是nums中缺失的
        }
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Missing-Number/Missing-Number.py)
###  方法一：哈希表
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_table = {}
        for num in nums:
            try:
                hash_table.pop(num)
            except:
                hash_table[num] = 1
        res = hash_table.popitem()[0]  ## Python 字典 popitem() 方法随机返回并删除字典中的最后一对键和值。如果字典已经为空，却调用了此方法，就报出KeyError异常。
        return res
```
### 方法二 ：数学方法(其他语言会溢出)
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        res = 2*sum(set(nums)) - sum(nums)  ## set() 函数创建一个无序不重复元素集，可进行关系测试，删除重复数据，还可以计算交集、差集、并集等。
        return res
```

### 方法二 ：数学方法(异或)
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res = res ^ num
        return res
```

# 参考

  -  [C++中map和unordered_map的用法](https://blog.csdn.net/jingyi130705008/article/details/82633778)
  -  [C++中unordered_set用法](https://blog.csdn.net/xiaoqiaxiaoqi/article/details/80531742)
  -  [Python set() 函数](https://www.runoob.com/python/python-func-set.html)
  -  [剑指offer_53题——0~n-1中缺失的数字](https://github.com/bryceustc/CodingInterviews/blob/master/MissingNumber/README.md)
