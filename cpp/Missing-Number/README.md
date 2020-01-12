# 题目描述:  缺失数字

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

方法二：数学方法，相减，0-n相加再减去nums数组所有元素之和。异或：``res = nums.size()``，res与nums中的元素异或，在与i异或，如果nums[i]和i都存在，则异或为0，缺失的数字就与i相对应，异或满足交换律。

方法三：排序法，将数组按顺序排序，数组元素与与相对应下标是否相等，若不相等则返回相应的下标，即为缺失数字。
# 时间复杂度：
  方法一： O(n)
  
  方法二： O(n) 
  
  方法三： O(nlogn)
# 空间复杂度
  方法一：O(n)
  
  方法二：O(1)
  
  方法三：空间复杂度取决于使用的排序算法，根据排序算法是否进行原地排序（即不使用额外的数组进行临时存储），空间复杂度为 O(1) 或 O(n)。
  
# 代码

## [C++](./Missing-Number.cpp):

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

### 方法三： 排序
```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        if (nums[n-1]!=n)
        {
            return n;
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=i)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Missing-Number/Missing-Number.py)
###  方法一：哈希表
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        nums_set = set(nums)
        for num in range(n+1):
            if num not in nums_set:
                return num
        return res
```
### 方法二 ：数学方法
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0;
        n = len(nums)
        x = range(n+1)
        x = list(x)           ### Python3 需要用list转换成数组
        res = sum(x)-sum(nums)
        return res
```

### 方法二 ：数学方法(异或)
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        res = n
        for i in range(n):
            res = res ^ nums[i]
            res = res ^ i
        return res
```

### 方法三：排序法
```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums = sorted(nums)
        n = len(nums)
        if nums[-1] != n:
            return n
        for i in range(0,n):
            if i!=nums[i]:
                return i
```



# 参考

  -  [C++中map和unordered_map的用法](https://blog.csdn.net/jingyi130705008/article/details/82633778)
  -  [C++中unordered_set用法](https://blog.csdn.net/xiaoqiaxiaoqi/article/details/80531742)
  -  [Python set() 函数](https://www.runoob.com/python/python-func-set.html)
  -  [剑指offer_53题——0~n-1中缺失的数字](https://github.com/bryceustc/CodingInterviews/blob/master/MissingNumber/README.md)
