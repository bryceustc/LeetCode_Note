# 题目描述:  水壶问题

有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：
    
  - 装满任意一个水壶
  - 清空任意一个水壶
  - 从一个水壶向另外一个水壶倒水，直到装满或者倒空

**示例 :**
```
输入: x = 3, y = 5, z = 4
输出: True
```
# 解题思路:
  扩展欧几里得算法，找到x,y的最大公约数能否z被整除
  
# 代码

###  调用gcd库函数
```c++
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z==0) return true;
        if(x+y<z) return false;
        int a = min(x,y);
        int b = max(x,y);
        if (a==0)
            return b==z;
        // 求最大公约数
        int c = __gcd(a,b);
        return z%c==0;
    }
};
```
### 自写gcd函数（迭代）
```c++
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if (x+y<z) return false;
        int a = min(x,y);
        int b = max(x,y);
        if (a==0) 
            return b==z;
        int c = my_gcd(a,b);
        return z%c==0;
    }
    int my_gcd(int a, int b)
    {
        while(b!=0)
        {
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
};
```
### 自写gcd函数（递归）
```c++
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
        if (x+y<z) return false;
        int a = min(x,y);
        int b = max(x,y);
        if (a==0) 
            return b==z;
        int c = my_gcd(a,b);
        return z%c==0;
    }
    int my_gcd(int a, int b)
    {
    //    if (b!=0)
    //    {
    //        return my_gcd(b,a%b);
    //    }
    //    else
    //    {
    //        return a;
    //    }
       return b==0?a:my_gcd(b,a%b);
    }
};
```
## 参考
  - [字符串的最大公因子](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Greatest-Common-Divisor-Of-Strings/README.md)
