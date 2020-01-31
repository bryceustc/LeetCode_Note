# 题目描述:  数字 1 的个数

给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
**示例 :**
```
输入: 13
输出: 6 
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
```
  
# 解题思路:
此题与剑指offer第四十三题一样

方法一：暴力遍历，对1\~n进行遍历，每一个数字都进行判断，从最高位一直判断到最低位，每次通过对10求余数判断整数的个位数字是不是1，大于10的除以10之后再判断。我们对每个数字都要做除法和求余运算以求出该数字中1出现的次数。如果输入数字n，n有O(logn)位，我们需要判断每一位是不是1，那么时间复杂度为O(n\*logn),空间复杂度O(1)。

方法二：数学归纳，寻找数学规律，数学之美中的方法，利用数学归纳法进行判定，设定整数点（如1、10、100等等）作为位置点i（对应n的个位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析。下边以百位为例，即``i=100``
  
  - 根据设定的整数位置，对n进行分割，分为两部分，高位 ``a = n/i``，低位``b = n%i``
  - 当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a/10+1)\*100个点的百位为1
  - 当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a/10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a/10\*100）+(b+1)，这些点百位对应为1\
  - 当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）
  - 综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
  - 之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
 
# 时间复杂度：
  方法一：O(n\*logn)
  
  方法二： O(logn)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Number-Of-Digit-One.cpp):

###  方法一： 直接暴力遍历法（未通过OJ）
```c++
class Solution {
public:
    int countDigitOne(int n) {
        int res =0;
        if (n<1)
            return res;
        for (int i=1;i<=n;i++)
        {
            res+=NumberOf1(i);
        }
        return res;
    }
    int NumberOf1(int n)
    {
        int num =0;
        while(n)
        {
            if (n%10==1)
            {
                num++;
            }
            n /= 10;
        }
        return num;
    }
};
```

###  方法二： 数学规律
```c++
class Solution {
public:
    int countDigitOne(int n) {
        long int res = 0;
        for (long int i=1;i<=n;i*=10)
        {
            long int a = n/i;
            long int b = n%i;
            res += (a+8)/10*i + (a%10==1)*(b+1);
        }
        return res;
    }
};
```

###  方法三： 转成字符串，可以表示更大的数字
```c++
class Solution {
public:
    int countDigitOne(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string str = to_string(i);
            res += count(str.begin(), str.end(), '1');
        }
        return res;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Number-Of-Digit-One/Number-Of-Digit-One.py)
###  方法一：暴力遍历法(超时)
```python
class Solution:
    def countDigitOne(self, n: int) -> int:
        res = 0
        for i in range(1,n+1):
            res+=self.NumberOf1(i)
        return res
    def NumberOf1(self, n: int):
        num = 0
        while n>0:
            if (n%10==1):
                num+=1
            n//=10
        return num
```
### 方法二 ：遍历+一次二分查找
```python
class Solution:
    def countDigitOne(self, n: int) -> int:
        res = 0
        i = 1
        while i<=n:
            a = n // i
            b = n % i
            res += (a+8)//10*i + (a%10==1)*(b+1)
            i*=10
        return res
```
# 参考

  -  [剑指Offer-43题-1~n整数中1出现的次数](https://github.com/bryceustc/CodingInterviews/blob/master/NumberOf1/README.md)
