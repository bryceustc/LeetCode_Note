# 题目描述:  最长回文子序列

给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

**示例 :**
```
输入:
"bbbab"

输出:
4

解释:
一个可能的最长回文子序列为 "bbbb"。
```
# 解题思路:
  子序列问题，不想子串，子数组是连续的，子序列可以是不连续的，基本上都要用动态规划来实现。
  
**状态定义：** 
  - dp[i][j]表示s[i..j]代表的字符串的最长回文子序列
  
**转移方程：** 
  - 当s[i]==s[j]时：dp[i][j] = dp[i+1][j-1]+2;
  - 当s[i]!=s[j]时：dp[i][j] = max(dp[i+1][j],dp[i][j-1]); **着重理解：如果它俩不相等，说明它俩不可能同时出现在 s[i..j] 的最长回文子序列中**
  (当s[i]!=s[j]时， dp[i][j]=max(dp[i+1][j],dp[i][j-]) 这种情况，只有这种情况下a'aaa'b，一端为a，一端为b，不相等，此时dp[i+1][j] > dp[i][j-1]，还有b'aaa'a同理，其他情况下，dp[i][j] = dp[i+1][j] = dp[i][j-1] = dp[i+1][j-1]，因为这时只加一个字符时不可能组成回文子序列。)
  
**初始状态：**
  - dp[i][i] = 1 单个字符的最长回文序列是 1
  
**返回结果**
  - dp[0][n-1]
  
# 代码

###  dp
```c++
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        // 状态定义：dp[i][j]表示s[i..j]代表的字符串的最长回文子序列
        vector<vector<int>> dp(n, vector<int>(n,0));
        // 初始化状态
        for (int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }
        // 反着遍历保证正确的状态转移
        for(int i=n-1;i>=0;i--)
        {
            for (int j=i+1;j<n;j++)
            {
                // 状态转移方程
                if (s[i]==s[j])
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);// a'aaa'b这种
                }
            }
        }
        // 返回结果
        return dp[0][n-1];
    }
};
```
