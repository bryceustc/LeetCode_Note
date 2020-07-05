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
  dp
  
  定义状态:dp[i][j]表示字符串 s 的前 i 个字符和模式 p 的前 j 个字符是否能匹配
  
  状态转移方程：
   ``` 
   if (p[j-1]=='*') {
       dp[i][j] = dp[i][j-1] | dp[i-1][j];
   } 
    else {
       if (p[j-1]=='?' || s[i-1]==p[j-1]) {
          dp[i][j] = dp[i-1][j-1];
         }
   }

# 时间复杂度：
  时间复杂度：O(mn)。
  
# 空间复杂度
  O(mn)。
  
# 代码

###
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1]=='*') {
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                } else {
                    if (p[j-1]=='?' || s[i-1]==p[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
```

# 参考
  - [字符串匹配](https://github.com/bryceustc/CodingInterviews/blob/master/RegularExpressionsMatching/README.md)
