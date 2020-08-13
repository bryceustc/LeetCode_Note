# 题目描述: 字符串相乘(可实现大数相乘，不受int和long的限制)

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

**示例 1:**
```
输入: num1 = "2", num2 = "3"
输出: "6"
```

**示例 2:**
```
输入: num1 = "123", num2 = "456"
输出: "56088"
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

## [C++](./Multiply-Strings.cpp):

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

### 普通竖式法相加
```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size();
        int m = num2.size();
        string res;
         // num2 逐位与 num1 相乘
        for (int i = m - 1; i >=0; i--) {
            int t = 0;
            int b = num2[i] - '0';
             // 保存 num2 第i位数字与 num1 相乘的结果
            string temp;
            for (int j = n- 1; j >=0; j--) {
                t += (num1[j] - '0') * b;
                temp += t %10 + '0';
                t /= 10;
            }
            if (t>0) temp += t + '0';
            // 注意翻转
            reverse(temp.begin(), temp.end());
            // 补0
            for (int k = m - 1 - i; k>0; k-- ) {
                temp += "0";
            }
            // 将当前结果与新计算的结果求和作为新的结果
            res = add(res, temp);
        }
        return res;
    }

    /**
     * 对两个字符串数字进行相加，返回字符串形式的和
     */
    string add (string num1, string num2) {
        string res;
        int n = num1.size();
        int m = num2.size();
        int t = 0;
        for (int i = n-1, j = m-1; i >= 0 || j >= 0; i--, j--) {
            if ( i>=0 ) t += num1[i] - '0';
            if (j >= 0) t += num2[j] - '0';
            res += t % 10 + '0';
            t /= 10;
        }
        if (t) res += t + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Multiply-Strings/Multiply-Strings.py)
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
  - [字符串相加](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Add-Strings/README.md)
