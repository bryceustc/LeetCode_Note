# 题目描述:  有效数字

验证给定的字符串是否可以解释为十进制数字。

```
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
```

**说明：**

我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：

  - 数字 0-9
  - 指数 - "e"
  - 正/负号 - "+"/"-"
  - 小数点 - "."
  - 当然，在输入中，这些字符的上下文也很重要。

 
# 解题思路:
  此题与剑指Offer第二十题类似，但比二十题复杂，有空格情况。
  
  所有的字符可以分为六大类，空格，符号，数字，小数点，自然底数和其他字符，我们需要五个标志变量，num, decimal, hasE, sign分别表示数字，小数点，自然底数和符号是否出现，numAfterE表示自然底数后面是否有数字，那么我们分别来看各种情况：

- 空格： 我们需要排除的情况是，当前位置是空格而后面一位不为空格，但是之前有数字，小数点，自然底数或者符号出现时返回false。

- 符号：符号前面如果有字符的话必须是空格或者是自然底数，标记sign为true。

- 数字：标记num和numAfterE为true。

- 小数点：如果之前出现过小数点或者自然底数，返回false，否则标记dot为true。

- 自然底数：如果之前出现过自然底数或者之前从未出现过数字，返回false，否则标记exp为true，numAfterE为false。

- 其他字符：返回false。

最后返回num && numAfterE即可。
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Valid-Number.cpp):

###  方法一： 
```c++
class Solution {
public:
    bool isNumber(string s) {
        bool num = false, numAfterE = true, decimal = false, hasE = false, sign = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) 
        {
            if (s[i] == ' ') 
            {
                if (i < n - 1 && s[i + 1] != ' ' && (num || decimal || hasE || sign)) return false;
            } 
            else if (s[i] == '+' || s[i] == '-') 
            {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
                sign = true;
            } 
            else if (s[i] >= '0' && s[i] <= '9') 
            {
                num = true;
                numAfterE = true;
            } 
            else if (s[i] == '.') 
            {
                if (decimal || hasE) return false;
                decimal = true;
            } 
            else if (s[i] == 'e') 
            {
                if (hasE || !num) return false;
                hasE = true;
                numAfterE = false;
            } else return false;
        }
        return num && numAfterE;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Valid-Number/Valid-Number.py)
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

  -  [剑指Offer-20题-表示数值的字符串](https://github.com/bryceustc/CodingInterviews/blob/master/NumericStrings/README.md)

