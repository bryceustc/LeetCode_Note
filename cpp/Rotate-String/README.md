# 题目描述:  旋转字符串

给定两个字符串, ``A`` 和 ``B``。

``A`` 的旋转操作就是将 ``A`` 最左边的字符移动到最右边。 例如, 若 ``A = 'abcde'``，在移动一次之后结果就是``'bcdea'``。如果在若干次旋转操作之后，``A`` 能变成``B``，那么返回``True``。

**示例 1:**
```
示例 1:
输入: A = 'abcde', B = 'cdeab'
输出: true
```
**示例 2:**
```
示例 2:
输入: A = 'abcde', B = 'abced'
输出: false
```

# 解题思路:
    此题与剑指offer的第50题左旋转字符串类似，但比那题稍微复杂一点
    
    方法一：直接左移，定义一个左移函数。左移判断是否相等
    
    方法二：直接``A+A``，判断B是否在A+A这个里边。
# 时间复杂度：
  O(n<sup>2</sup>)
# 空间复杂度
  方法一：O(1)
  
  方法二：O(n)
  
# 代码

## [C++](./Rotate-String.cpp):

###  直接法
```c++
class Solution {
public:
    bool rotateString(string A, string B) {
        int n = A.size();
        int m = B.size();
        bool res = false;
        if (n!=m) return res;
        if (A.empty()&&B.empty()) return true;
        for (int i=0;i<n;i++)
        {
            leftmove(A);
            if (!A.compare(B))
            {
                res = true;
                return res;
            }
        }
        return res;
    }
    void leftmove(string &s)
    {
        int n = s.size();
        char temp;
        temp = s[0];
        for (int i=0;i<n;i++)
        {
            if (i!=n-1)
            {
                s[i] = s[i+1];
            }
            else
            {
                s[i] = temp;
            }
        }
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Rotate-String/Rotate-String.py)
###  定义左移函数：
```python
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        n = len(A)
        m = len(B)
        if n!=m:
            return False
        if A=="" and B=="":
            return True
        for i in range(n):
            A = self.leftmove(A)
            if A==B:
                return True
        return False
    
    def leftmove(self,s):
        s = list(s)
        n = len(s)
        temp = s[0]
        for i in range(n):
            if i!=n-1:
                s[i]=s[i+1]
            else:
                s[i]=temp
        return ''.join(s)
```
## A+A判断
```python
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        n = len(A)
        m = len(B)
        if n!=m:
            return False
        if A=="" and B == "":
            return True
        if B in (A+A):
            return True
        return False
```

# 参考

  -  [剑指offer-50题-左旋转字符串](https://github.com/bryceustc/CodingInterviews/blob/master/LeftRotateString/README.md)

