# 题目描述:  最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

**示例 :**
```
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
```
**示例 :**
```
输入: "cbbd"
输出: "bb"
```

# 解题思路:
  1.dp
  
  2.中心扩展法
  
# 代码

###  
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n<2) return s;
        int start =0;
        int maxlen =1;
        // 定义状态：dp[i][j]表示s[i,j]是否为回文子串
        vector<vector<int>> dp(n,vector<int>(n,0));
        // 初始状态 dp[i][i]=1
        for (int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }
        for(int j=1;j<n;j++)
        {
            for (int i=0;i<j;i++)
            {
                // 状态转移方程
                if (s[i]==s[j])
                {
                    if ((j - 1) - (i + 1) + 1 < 2)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }

                if (dp[i][j]==1) // 只要 dp[i][j] == 1 成立，就表示子串 s[i, j] 是回文，此时记录回文长度和起始位置
                {
                    if (maxlen<j-i+1)
                    {
                        maxlen = j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
```
### 中心扩展(推荐)
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2) return s;
        string res;
        int start = 0;
        int maxlen = 0;
        for (int i=0;i<n-1;i++)
        {
            findPalindrome(s,start,i,i,maxlen); // 奇数情况，i为中心
            findPalindrome(s,start,i,i+1,maxlen); // 偶数情况，中间两个为中心
        }
        res = s.substr(start,maxlen);
        return res;
    }
    void findPalindrome(string s, int &start, int left, int right, int &maxlen)
    {
        while(left>=0 && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (maxlen < (right-1)-(left+1)+1)
        {
            start = left+1;
            maxlen = (right-1)-(left+1)+1;
        }
    }
};
```
