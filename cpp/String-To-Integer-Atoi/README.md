# 题目描述:  字符串转换整数 (atoi)

请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

**说明：**

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。


**示例 1:**
```
输入: "42"
输出: 42
```

**示例 2:**
```
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
```
**示例 3:**
```
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
```
**示例 4:**
```
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
```
**示例 5:**
```
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
```
  
# 解题思路:
  此题与剑指Offer第六十七题类似。
  就是要考虑到很多边界情况进行分析 
  - 忽略所有行首空格，找到第一个非空格字符，可以是 ‘+/−+/−’ 表示是正数或者负数，紧随其后找到最长的一串连续数字，将其解析成一个整数；
  - 整数后可能有任意非数字字符，请将其忽略；
  - 从前往后遍历时，如果第一段连续数字为空，则返回0；
  - 如果整数大于INT_MAX，请返回int_MAX；如果整数小于INT_MIN，请返回INT_MIN；
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./String-To-Integer-Atoi.cpp):

###  方法一： 回溯全排列法（未通过OJ）
```c++
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i = 0;
        int flag = 1;
        // 1. 检查空格和回车
        while (i < str.size() && (str[i] == ' ' || str[i] == '\t')) 
        { 
            i++; 
        }
        if (i >str.size()) 
            return 0;
        // 2. 检查符号
        if (str[i] == '-') 
        { 
            flag = -1;
            i++;
        }
        if (str[i] == '+') 
        { 
            if (flag == -1)
                return 0;
            else 
                i++;
        }
        // 3. 计算数字
        while (str[i]>='0' && str[i] <='9')
        {
            int r = str[i] - '0';
            if ((res > INT_MAX /10 || (res == INT_MAX /10 && r > 7)))//比较最后一位 /是去掉最后一位，&是取最后一位
            {
                if (flag > 0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            res = res*10 + r;
            i++;
        }
        
        res *= flag;
            
        return res;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/String-To-Integer-Atoi/String-To-Integer-Atoi.py)
###  方法一：
```python
class Solution:
    def myAtoi(self, str: str) -> int:
        res = 0;
        r = 0
        i = 0;
        flag = 1;
        
        if len(str) == 0:
            return 0
        
        while (i < len(str) and (str[i]==' ' or str[i]=='/t')):
            
            i+=1
        if (i > len(str)):
            return 0
        
        if (i < len(str) and str[i]=='-'):
            flag = -1
            i+=1
        if (i < len(str) and str[i]=='+'):
            if(flag == -1):
                return 0
            i+=1
        
        while (i < len(str) and str[i] >= '0' and str[i] <= '9'):
            r = int (ord(str[i]) - ord('0'))
            res = res * 10 + r
            i+=1
        res *=flag
        if res > (pow(2,31) - 1):
            res = pow(2,31) - 1
        if res < -(pow(2,31)):
            res = -pow(2,31)
        return res
```
# 参考

  -  [剑指Offer-67题-把字符串转换成整数](https://github.com/bryceustc/CodingInterviews/blob/master/StringToInt/README.md)
