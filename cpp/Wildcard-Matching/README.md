# 题目描述: 通配符匹配

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

```c++
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
```

两个字符串完全**匹配**才算匹配成功。

**说明:**

  - s 可能为空，且只包含从 a-z 的小写字母。
  - p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

**示例 1:**
```
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```

**示例 2:**
```
输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
```

**示例 3:**
```
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
```

**示例 4:**
```
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
```

**示例 5:**
```
输入:
s = "acdcb"
p = "a*c?b"
输入: false
```


  
# 解题思路:
  该算法是通过两数相乘时，乘数某位与被乘数某位相乘，与产生结果的位置的规律来完成。具体规律如下：
  
  - 乘数 ``num1`` 位数为 M，被乘数 ``num2`` 位数为 N， ``num1 x num2`` 结果 ``res`` 最大总位数为 M+N
  - ``num1[i] x num2[j]`` 的结果为 ``tmp``(位数为两位，"0x","xy"的形式)，其第一位位于 ``res[i+j]``，第二位位于 ``res[i+j+1]``。
  
  ![multiply](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Multiply-Strings/Image/multiply.png)

# 时间复杂度：
  时间复杂度：O(MN)。M,N 分别为 num1 和 num2 的长度。
  
# 空间复杂度
  O(M+N)。用于存储计算结果。
  
# 代码

## [C++](./Wildcard-Matching.cpp):

###
```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        string res(n1+n2,'0');
        for(int i=n2-1;i>=0;i--)
        {
            for(int j=n1-1;j>=0;j--)
            {
                int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
                res[i+j+1]=temp%10+'0';//当前位
                res[i+j]+=temp/10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }
        
        //去除首位'0'
        for(int i=0;i<n1+n2;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";
    }
};
```

### 以下是当时错误解法： 普通竖式法，未通过OJ，本质还是int乘法，
```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if (num1 == "0"||num2 =="0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        int carry = 0;
        int sum = 0;
        int sum_value = 0;
        for (int j = n2-1;j>=0;j--)
        {
            int temp = 0;
            for (int i = n1-1;i>=0;i--)
            {
                temp = (num2[j]-'0')*(num1[i]-'0')+carry;
                carry = temp / 10;
                sum += temp%10*(pow(10,n1-1-i));
                if (i==0 && carry!=0)
                {
                    sum += carry*(pow(10,n1));
                    carry = 0;
                }
            }
            sum_value += sum*(pow(10,n2-1-j));
            sum = 0;
        }
        res = to_string(sum_value);
        return res;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Wildcard-Matching/Wildcard-Matching.py)
### 优化竖式
```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1,n2 = len(num1),len(num2)
        res = [0 for i in range(n1+n2)]
        for i in range(n2-1,-1,-1):
            for j in range(n1-1,-1,-1):
                x,y = ord(num1[j])-ord('0'),ord(num2[i])-ord('0')
                temp = x*y + res[i+j+1]
                res[i+j+1] = temp % 10
                res[i+j] += temp // 10
        for i in range(0,n1+n2):
            if res[i] != 0:
                res = ''.join(str(x) for x in res[i:])
                return res
        return "0"
```
# 参考
  - [字符串相加](https://github.com/bryceustc/CodingInterviews/blob/master/DuplicationInArray/README.md)
