# 题目描述:  只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

**说明** 
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例 1:**
现有矩阵 matrix 如下：
```
输入: [2,2,1]
输出: 1
```
**示例 2:**
现有矩阵 matrix 如下：
```
输入: [4,1,2,1,2]
输出: 4
```
  
# 解题思路:

方法一：利用哈希表来做，``unordered_map<int,int> map``,``map[nums[i]]==1``。

方法二：对每一行使用一次二分查找，时间复杂度为O(m\*logn)

方法三：根据简单的例子寻找规律，从右上角开始寻找，时间复杂度为O(m+n)
 
# 时间复杂度：
  方法一： O(n)
  
  方法二： O(m\*logn)
  
  方法三： O(m+n) 
# 空间复杂度
  方法一：O(n)
  
  方法二：O()
  
# 代码

## [C++](./Single-Number.cpp):

###  方法一： 哈希表(unordered_map)  基于哈希表 ，map基于红黑二叉树
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =0;
        unordered_map<int,int> map;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int i=0;i<n;i++)
        {
            if (map[nums[i]]==1)
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
```
### 方法一：哈希表(unordered_set) 基于哈希表 ，set基于红黑二叉树
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        unordered_set<int> st;
        for (int num : nums) 
        {
            if (st.find(num)!=st.end()) // if (st.count(num))
                st.erase(num);
            else 
                st.insert(num);
        }
        res = *st.begin();
        return res;
    }
};
```



###  方法二： 数学方法(异或)(二进制)
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =  0;
        for (auto num:nums)
        {
            res = res ^ num;
        }
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Single-Number/Single-Number.py)
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



