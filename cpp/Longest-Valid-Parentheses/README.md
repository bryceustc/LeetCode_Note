# 题目描述:  最长有效括号

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

**示例 :**
```
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
```
# 解题思路:
  括号类问题，一般优先考虑用栈来解决。
  
1. 栈

与找到每个可能的子字符串后再判断它的有效性不同，我们可以用栈在遍历给定字符串的过程中去判断到目前为止扫描的子字符串的有效性，同时能的都最长有效字符串的长度。我们首先将 −1-1−1 放入栈顶。

对于遇到的每个 '(' ，我们将它的下标放入栈中。
对于遇到的每个 ')' ，我们弹出栈顶的元素并将当前元素的下标与弹出元素下标作差，得出当前有效括号字符串的长度。通过这种方法，我们继续计算有效子字符串的长度，并最终返回最长有效子字符串的长度。

2. dp


  
# 代码

###  栈
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
      int res = 0;
      int start = 0;
      int n = s.size();
      stack<int> stk;
      stk.push(-1);
      for (int i = 0; i < n; i++)
      {
        if(s[i]=='(')
          stk.push(i);
        else
        {
            stk.pop();//括号匹配，出栈
            if (stk.empty())
            {
              stk.push(i);
            }
            else
            {
              res = max(res,i-stk.top());
            }
        }
      }
      return res;
    }
};
```
### dp
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        vector<int> dp(n,0);
        for (int i=1;i<n;i++)
        {
            if (s[i]==')')
            {
                if (s[i-1]=='(')
                {
                    dp[i] = (i-2>=0? dp[i-2] : 0) +2;
                }
                else if (i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                {
                    dp[i] = (i-dp[i-1]-2>0? dp[i-dp[i-1]-2]:0)+dp[i-1]+2;
                }
                res = max(res,dp[i]);
            }
        }
        return res;
    }
};
```
