# 题目描述:  正则表达式匹配

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '\*' 的正则表达式匹配。

```
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
```
所谓匹配，是要涵盖**整个**字符串 s的，而不是部分字符串。

**说明 :**

1. s 可能为空，且只包含从 a-z 的小写字母。

2. p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 /*。

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
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
```

**示例 3:**
```
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
```

**示例 4:**
```
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
```
**示例 5:**
```
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
```

# 解题思路:
此题与剑指offer第19题一样

方法一：回溯法，我们先分析下如何匹配一个字符，现在只考虑字符'.'，不考虑'\*'看一下：

如果字符串和模式串的当前字符相等，那么我们继续匹配它们的下一个字符；如果模式串中的字符是'.'，那么它可以匹配字符串中的任意字符，我们也可以继续匹配它们的下一个字符。

接下来，把字符'\*'考虑进去，它可以匹配任意次的字符，当然出现0次也可以。

我们分两种情况来看：

模式串的下一个字符不是'\*'，也就是上面说的只有字符'.'的情况。 如果字符串中的第一个字符和模式串中的第一个字符相匹配，那么字符串的模式串都向后移动一个字符，然后匹配剩余的字符串和模式串。如果字符串中的第一个字符和模式中的第一个字符不相匹配，则直接返回false。

模式串的下一个字符是'\*'，此时就要复杂一些。 因为可能有多种不同的匹配方式。

选择一：无论字符串和模式串当前字符相不相等，我们都将模式串后移两个字符，相当于把模式串中的当前字符和''忽略掉，因为''可以匹配任意次的字符，所以出现0次也可以。

选择二：如果字符串和模式串当前字符相等，则字符串向后移动一个字符。而模式串此时有两个选择：

1、我们可以在模式串向后移动两个字符，继续匹配；

2、也可以保持模式串不变，这样相当于用字符'\*'继续匹配字符串，也就是模式串中的字符'\*'匹配字符串中的字符多个的情况。

方法二：动态规划
1、 设状态 dp(i,j)表示字符串 s 的前 i 个字符和字符串 p 的前 j 个字符能否匹配。这里假设 s 和 p 的下标均从 1 开始。初始时，dp(0,0)=true。

2、 平凡转移 dp(i,j)=dp(i,j) or dp(i−1,j−1)，当 i>0 且 s(i) == p(j) || p(j) == '.'。

3、 当 p(j) == '\*' 时，若 j>=2，dp(i,j)可以从 f(i,j−2)转移，表示丢弃这一次的 '\*' 和它之前的那个字符；若 i>0且 s(i) == p(j - 1)，表示这个字符可以利用这个 '\*'，则可以从dp(i−1,j) 转移，表示利用 '\*'。

4、 初始状态 dp(0,0)=true；循环枚举 i 从 0 到 n；j 从 1 到 m。因为 dp(0,j)有可能是有意义的，需要被转移更新。

5、 最终答案为 dp(n,m)。
# 时间复杂度：
  方法一： O(n)
  
  方法二： O(nm)
  
# 空间复杂度
  方法一：O(n)
  
  方法二：O(nm)
  
# 代码

## [C++](./Regular-Expression-Matching.cpp):

###  方法一： 回溯法
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) 
            return s.empty();
        if (p[1]!='*')
        {
            if (s[0]==p[0] || p[0]=='.' && !s.empty())
                return isMatch(s.substr(1),p.substr(1));
            else
                return false;
        }
        else
        {
            if (s[0]==p[0] || p[0]=='.' && !s.empty())
                return (isMatch(s,p.substr(2)) || isMatch(s.substr(1),p));
            else
                return isMatch(s, p.substr(2));
        }
    }
};
```

###  方法二： 动态规划
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        s = " " + s;
        p = " " + p;
        for (int i = 0; i <= n; i++)  // 从0开始，因为dp(0,j)有可能是有意义的
        {
            for (int j = 1; j <= m; j++) 
            {
                if (i > 0 && (s[i] == p[j] || p[j] == '.'))
                    dp[i][j] = dp[i][j] | dp[i - 1][j - 1]; // 表示按位或
                if (p[j] == '*') 
                {
                    if (j >= 2)
                        dp[i][j] = dp[i][j] | dp[i][j - 2];
                    if (i > 0 && (s[i] == p[j - 1] || p[j - 1] == '.'))
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Regular-Expression-Matching/Regular-Expression-Matching.py)
###  方法一：回溯法
```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(s)==0 and len(p)==0:
            return True
        if len(s)!=0 and len(p)==0:
            return False
        if  len(p)>1 and p[1]=='*':
            if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
                return self.isMatch(s,p[2:]) or self.isMatch(s[1:],p)
            else:
                return self.isMatch(s,p[2:])
        if len(s)>0 and (s[0] == p[0] or p[0]=='.'):
            return self.isMatch(s[1:],p[1:])
        else:
            return False
```
### 方法二 ：插入排序
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        for i in range(0,n):
            if nums[i]==0:
                for j in range(i+1,n):
                    if nums[j]!=0:
                        temp = nums[j]
                        for k in range (j,i,-1):
                            nums[k] = nums[k-1]
                        nums[i] = temp
                        break
```

# 参考

  -  [剑指offer_19题_正则表达式匹配](https://github.com/bryceustc/CodingInterviews/blob/master/RegularExpressionsMatching/README.md)





