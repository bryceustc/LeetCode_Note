# 题目描述:  字符串的最大公因子

对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。


**示例 :**
```
输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
```
**示例 :**
```
输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
```

# 解题思路:
  [欧几里德算法](https://baike.baidu.com/item/%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95)，求最大公约数
  
  有个trick，如果它们有公因子 abc，那么 str1 就是 m 个 abc 的重复，str2 是 n 个 abc 的重复，连起来就是 m+nm+nm+n 个 abc，好像 m+n个 abc 跟 n+m 个 abc 是一样的。

所以如果 str1 + str2 === str2 + str1 就意味着有解。

我们也很容易想到 str1 + str2 !== str2 + str1 也是无解的充要条件。

当确定有解的情况下，最优解是长度为 gcd(str1.length, str2.length) 的字符串。

# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## C++
### 使用c++自带__gcd函数
```c++
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1+str2 != str1 + str2) return "";
        return str1.substr(0,__gcd((int)str1.length(), (int)str2.length())); // __gcd() 为c++自带的求最大公约数的函数
    }
};
```
###  自己定义gcd函数
```c++
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd((int)str1.length(), (int)str2.length()));
    }

    // int gcd(int a , int b)
    // {
    //     if (b==0)
    //     {
    //         return a;
    //     }
    //     int temp = a%b;
    //     return gcd(b, temp);
    // }


    // int gcd(int a, int b)
    // {
    //     while(b>0)
    //     {
    //         int temp = a%b;
    //         a = b;
    //         b = temp;
    //     }
    //     return a;
    // }

    int gcd(int a, int b)
    {
        return b==0?a:gcd(b, a%b);
    }
};
```

