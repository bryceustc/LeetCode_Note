# 题目描述:  Pow(x, n)

实现 ``pow(x, n)`` ，即计算 x 的 n 次幂函数。


**示例 1:**
```
输入: 2.00000, 10
输出: 1024.00000
```

**示例 2:**
```
输入: 2.10000, 3
输出: 9.26100
```

**示例 3:**
```
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
```

**说明：**

  - -100.0 < x < 100.0
  - n 是 32 位有符号整数，其数值范围是 [−2<sup>31</sup>, 2<sup>31</sup> − 1]。

  
# 解题思路:
  方法一：直接根据定义暴力求解

# 时间复杂度：
  O(N)
# 空间复杂度
  O(1)
  
# 代码

## [C++](./PowX-N.cpp):

### 方法一： 暴力求解法
```c++
class Solution {
public:
    double myPow(double x, int n) {
        double res=x;
        if (x==0) return 0;
        if (x==1) return 1;
        if (x==-1 && n%2==0) return 1;
        if (x==-1 && n%2!=0) return -1;
        if (n==-2147483648 && x>1) 
        {
            res = 0.0;
            return res;
        }
        if (n==2147483647 && x<-1) 
        {
            res = 0.0;
            return res;
        }
        if (n>0)
        {
            for (int i=1;i<n;i++)
            {
                res=res*x;
            }
        }
        if (n<0)
        {
            for (int i=-1;i>n;i--)
            {
                res=res*x;
            }
            res = 1/res;
        }
        if (n==0)
            res = 1;
        return res;
    }
};
```

### 方法二：哈希表
```c++
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        int n = strs.size();
        unordered_map<string,vector<string>> record;
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            record[temp].push_back(str);
        }
        for (auto& m:record)
        {
            res.push_back(m.second);  //m是record里边的元素，利用操作符'.'进行索引第2个,下标i是迭代器，用法类似指针，用i->second索引
        }
        // for (auto i = record.begin();i!=record.end();i++)
        // {
        //     res.push_back(i->second);
        // }    
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/PowX-N/PowX-N.py)
### 方法一： 暴力求解法
```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = x
        if x==0:
            return 0
        if x==1:
            return 1
        if x==-1 and n%2 == 0:
            return 1
        if x==-1 and n%2 != 0:
            return -1
        if n==2147483647 and x<1:
            return 0
        if n==-2147483648 and x>1:
            return 0
        if n>0:
            for i in range(1,n):
                res *= x
        if n<0:
            for i in range(-1,n,-1):
                res *=x
            res = 1/res
        if n==0:
            res = 1
        return res;
```
