# 题目描述:  单词拆分

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

**说明** 

  - 拆分时可以重复使用字典中的单词。
  - 你可以假设字典中没有重复的单词

**示例 1:**
```
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
```
**示例 2:**
```
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
```
  
# 解题思路:

动态规划：

- 定义状态：dp[i]表示字符串s的前i个字符能否拆分成wordDict。也就是长度为i的s（0，i-1）是否由字符表组成
![](https://pic.leetcode-cn.com/70b0957d0086f43cd56b9e311e03deed4e9a77be0ae40ccbaa2f2b006d7caeb5-image.png)

- 状态转移方程：

    用指针 j 去划分两部分

    [0, i] 区间子串 的 dp[i+1] 为真，取决于两部分：

    它的前缀子串 [0, j-1[0,j−1] 的 dp[j]为真

    剩余子串 [j,i]是一个合格的单词

![](https://pic.leetcode-cn.com/bcef185f09c72fb525855bd56155f4658793d86b0dc4f3de31cace6bd9398c5b-image.png)

- 初始化状态：dp[0] = 1, 表示空串且合法

- 返回结果：dp[n]
 
# 时间复杂度：
  O(n^2)
# 空间复杂度
  O(n)
  
# 代码

###  动态规划
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        // 定义状态：dp[i]表示字符串s的前i个字符能否拆分成wordDict
        vector<int> dp(n+1,0);
        // 初始化：dp[0] = 1
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j]==1 && (st.count(s.substr(j,i-j)))) {
                    dp[i] = 1;
                    break;  // i长度的子串已经满足要求，不需要j继续划分子串
                }
            }
        }
        // 返回结果
        return dp[n];
    }
};
```
