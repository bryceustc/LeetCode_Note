# 题目: 编辑距离

## 题目描述：
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

**示例1：**
 ```
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
 ```

**示例2：**
 ```
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 ```

# 解题思路:
  碰到两个字符串时，首先考虑一下动态规划
  
**状态定义：** 
  - dp[i][j]表示word1的前i个字母转换成word2的前j个字母所使用的最少操作数
  
**状态转移方程：** 
  - 当word1[i-1]==word2[j-1]时：dp[i][j] = dp[i-1][j-1]; 不需要操作
  - 当word1[i-1]!=word2[j-1]时：dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]); 
  
  **着重理解：** 
  
  增删替三个操作的最小值 + 1，dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作
  ```
  以 word1 为 "horse"，word2 为 "ros"，且 dp[5][3] 为例，即要将 word1的前 5 个字符转换为 word2的前 3 个字符，也就是将 horse 转换为 ros，因此有：

  (1) dp[i-1][j-1]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 2 个字符 ro，然后将第五个字符 word1[4]（因为下标基数以 0 开始） 由 e 替换为 s（即替换为 word2 的第三个字符，word2[2]）

  (2) dp[i][j-1]，即先将 word1 的前 5 个字符 horse 转换为 word2 的前 2 个字符 ro，然后在末尾补充一个 s，即插入操作

  (3) dp[i-1][j]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 3 个字符 ros，然后删除 word1 的第 5 个字符
  ```
**初始状态：**
  - dp[i][0] = i 第一列，是 word2 为空，需要的最少步数，就是删除操作
  - dp[0][j] = j 第一行，是 word1 为空变成 word2 最少步数，就是插入操作
  
**返回结果**
  - dp[m][n]
# 时间复杂度：
1: O(mn)
# 空间复杂度
 O(mn)
# 代码
###  dp
```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // 定义状态：dp[i][j],表示word1的前i个字母转换成word2的前j个字母所使用的最少操作数
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // 初始化状态
        for (int i=0;i<=m;i++)
        {
            dp[i][0]=i;
        }
        for (int j=0;j<=n;j++)
        {
            dp[0][j]=j;
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                // 状态转移方程
                if (word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 +  min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};
```

