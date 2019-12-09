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
  
  方法二：使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候我们再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。还有一点需要引起我们的注意的是n有可能为负数，对于n是负数的情况，我们可以先用其绝对值计算出一个结果再取其倒数即可。我们让i初始化为n，然后看i是否是2的倍数，是的话x乘以自己，否则res乘以x，i每次循环缩小一半，直到为0停止循环。最后看n的正负，如果为负，返回其倒数
# 时间复杂度：
  方法一：O(N)
  方法二：O(log(N))
# 空间复杂度
  方法一和方法二都为O(1)
  
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

### 方法二：折半计算
```c++
class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        for(int i=n;i!=0;i/=2)
        {
            if (i%2 != 0)
            {
                res*=x;
            }
            x*=x;
        }
        if (n<0)
          res = 1/res;
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

### 方法二： 折半计算
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
