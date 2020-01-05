# 题目描述: 字符串相加

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的和，它们的和也表示为字符串形式。

**注意：**

  1. num1 和num2 的长度都小于 5100.
  2. num1 和num2 都只包含数字 0-9.
  3. num1 和num2 都不包含任何前导零。
  4. **你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。**
  
# 解题思路:
  这道题让我们求两个字符串的相加，之前 LeetCode 出过几道类似的题目，比如二进制数相加，还有链表相加，或是字符串加1，基本思路很类似，都是一位一位相加，然后算和算进位，最后根据进位情况看需不需要补一个高位。

# 时间复杂度：
  时间复杂度：O(max(M,N))。M,N 分别为 num1 和 num2 的长度,按位遍历一遍数字（以较长的数字为准）
  
# 空间复杂度
  O(1)。指针与变量使用常数空间
  
# 代码

## [C++](./Add-Strings.cpp):

### 双指针
```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string res;
        while (i>=0 || j>=0)
        {
            int temp = 0;
            if (i<0)
                temp = num2[j]-'0'+carry;
            if (j<0)
                temp = num1[i]-'0'+carry;
            else
                temp = num1[i] - '0' + num2[j] -'0' + carry;
            carry = temp / 10;
            res.insert(res.begin(),temp%10+'0');
            i--;
            j--;
        }
        if (carry>0)
            res.insert(res.begin(),carry+'0');
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Add-Strings/Add-Strings.py)
### 双指针
```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res =""
        n1 = len(num1)
        n2 = len(num2)
        i = n1-1
        j = n2-1
        carry = 0
        while i >=0 or j >=0:
            if i < 0:
                temp = ord(num2[j]) - ord('0') + carry
            if j < 0:
                temp = ord(num1[i]) - ord('0') + carry
            if i>=0 and j>=0:
                temp = (ord(num1[i]) -ord('0')) + (ord(num2[j]) - ord('0')) + carry
            carry = temp // 10
            temp = temp%10
            res += str(temp)
            i=i-1
            j=j-1
        if carry>0:
            res+=str(carry)
        return res[::-1]
```
# 参考
  - [字符串相乘](https://github.com/bryceustc/LeetCode_Note/edit/master/cpp/Multiply-Strings/README.md)
  - [Python字符串反转](https://www.runoob.com/python3/python-string-reverse.html)
  - [string 的一些用法——插入（insert）、删除(erase)、替换(replace)和查找(find)](https://blog.csdn.net/dengheCSDN/article/details/77404317) 
