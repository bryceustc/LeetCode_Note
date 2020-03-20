# 题目描述:  最长公共子序列

给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

**示例 :**
```
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。
```
**示例 :**
```
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
```

# 解题思路:
  经典题型：LCS问题
  
# 代码

###  dp
```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.empty()||text2.empty()) return 0;
        int m = text1.size();
        int n = text2.size();
        // 定义状态：dp[i][j]表示text1[0~i-1]和text2[0~j-1]的最长公共子序列长度
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // 任何一个字符串为0时都是零，建立dp数组的时候就完成了初始化
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                // 状态转移方程：text1 的前 i-1 个字符与 text2 的前 j-1 个字符最长公共子序列加 1
                if (text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    // 不相等的时候，例如abc'e,abe'd,取abce和abe以及abc和abed的最大值
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
```
## 参考
    - [题解讨论](https://leetcode-cn.com/problems/longest-common-subsequence/solution/jian-dan-yi-dong-zui-chang-gong-gong-zi-xu-lie-by-/)
