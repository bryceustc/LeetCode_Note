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
            // 空格：当前位置是空格但下一位置不为空格并且之前出现过数字、自然底数、小数点、符号，如：1. 3,返回false
            if (s[i] == ' ') 
            {
                if (i < n - 1 && s[i + 1] != ' ' && (num || decimal || hasE || sign)) return false;
            } 
            // 符号：'+'和'-'要么出现在开头，要么出现在e之后，所以，'+'和'-'之前一位必须为'e'或者' ' 例：" +12"或"2e+2"
            else if (s[i] == '+' || s[i] == '-') 
            {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ' && s[i - 1] != 'E') return false;
                sign = true;
            } 
            // 数字：数字范围要在0~9之间
            else if (s[i] >= '0' && s[i] <= '9') 
            {
                num = true;
                numAfterE = true;
            } 
            // 小数点：小数点需在自然指数之后且只出现一次，否则无效。例："2e3.4" 无效
            else if (s[i] == '.') 
            {
                if (decimal || hasE) return false;
                decimal = true;
            } 
            // 自然底数：e需在数字之后且只能出现一次，否则无效，例 "e3"，无效
            else if (s[i] == 'e' || s[i] == 'E') 
            {
                if (hasE || !num) return false;
                hasE = true;
                numAfterE = false;
            } 
            // 其他字符出现：无效
            else return false;
        }
        return num && numAfterE;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Valid-Number/Valid-Number.py)
###  方法一：
```python
class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        if n==0:
            return False
        num = False
        numAfterE = False
        decimal = False
        sign = False
        hasE = False
        for i in range(n):
            if s[i]==' ':
                if (i<n-1 and s[i+1]!=' ' and (num or decimal or sign or hasE)):
                    return False
            elif s[i]=='+' or s[i]=='-':
                if i>0 and s[i-1]!='e' and s[i-1]!=' ':
                    return False
                sign = True
            elif s[i]>='0' and s[i]<='9':
                num =True
                numAfterE=True
            elif s[i]=='.':
                if hasE or decimal:
                    return False
                decimal = True
            elif s[i]=='e':
                if hasE or (num is False):
                    return False
                hasE = True
                numAfterE=False
            else:
                return False
        return num and numAfterE
```
# 参考

  -  [剑指Offer-20题-表示数值的字符串](https://github.com/bryceustc/CodingInterviews/blob/master/NumericStrings/README.md)

