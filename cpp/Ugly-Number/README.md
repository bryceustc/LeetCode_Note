# 题目描述:  丑数

编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 2, 3, 5 的**正整数**。

**示例1 :**
```
输入: 6
输出: true
解释: 6 = 2 × 3
```

**示例2 :**
```
输入: 8
输出: true
解释: 8 = 2 × 2 × 2
```

**示例3 :**
```
输入: 14
输出: false 
解释: 14 不是丑数，因为它包含了另外一个质因数 7。
```

**说明：**
  1. ``1``是丑数
  2. 输入不会超过 32 位有符号整数的范围: [−2<sup>31</sup>,  2<sup>31</sup> − 1]。

  
# 解题思路:
此题与剑指offer第四十五题类似

想要判断一个数的因子是否为2,3,5只需要判断对这个几个数进行取模看是否能够整除然后再除以这几个数，直到最后为1即是丑数，不是1则不为丑数。然后从1开始按照顺序判断每一个数是不是丑数。
 
# 时间复杂度：
  无法准确分析时间复杂度:至少O(n3)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Ugly-Number.cpp):

###  模拟法
```c++
class Solution {
public:
    bool isUgly(int num) {
        if (num<1)
            return false;
        while(num%5==0)
        {
            num/=5;
        }
        while(num%3==0)
        {
            num/=3;
        }
        while(num%2==0)
        {
            num/=2;
        }
        return num==1;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Search-A-2D-Matrix-II/Search-A-2D-Matrix-II.py)
###  模拟法
```python
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <1:
            return False
        while num%5 == 0:
            num//=5
        while num%3 == 0:
            num//=3
        while num%2 == 0:
            num//=2
        return num==1
```

# 参考

  -  [丑数II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Ugly-Number-II/README.md)
  -  [剑指Offer_49题丑数](https://github.com/bryceustc/CodingInterviews/blob/master/UglyNumber/README.md)



