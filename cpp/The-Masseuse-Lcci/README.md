# 题目描述:  按摩师

一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。


**示例 :**
```
输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。

输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
```

# 解题思路:
  动态规划：
  
  1. 定义状态：dp[i][j]，表示前i个预约，状态为j(0/1)的最大预约时间数。0为不接受当前预约，1为接受当前预约
  
  2. 状态转移方程：
  $$
   dp[i][0] = max(dp[i-1][0], dp[i-1][1]);   
   dp[i][1] = dp[i-1][0] + nums[i];
  $$
  
  3. 初始状态：
  
  dp[0][0] = 0;  dp[0][1] = nums[0];
  
  4. 返回结果：
   
   res = max(dp[n-1][0], dp[n-1][1]);
   
   5. 考虑状态压缩：
   ```
   int tdp_0 = max(dp_0, dp_1);
   tdp_1 = dp_0 + nums[i];
   dp_0 = tdp_0;
   dp_1 = tdp_1;
    ```
# 时间复杂度：
  O(n)
# 空间复杂度
  1: O(n)
  
  2: O(1)
  
# 代码
### dp
```c++
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        int res = 0;
        // 定义状态: dp[i][j]，表示前i个预约，状态为j(0/1)的最大预约时间数。0为不接受当前预约，1为接受当前预约
        vector<vector<int>> dp(n, vector<int> (2,0));
        // 初始状态
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i=1;i<n;i++)
        {
            // 状态转移方程
            // 今天不接受，可以是昨天也不接受，也可以是昨天接受了今天不接受
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            // 今天接受，那就是昨天不接受
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        // 返回结果
        res = max(dp[n-1][0], dp[n-1][1]);
        return res;
    }
};
```
###  双指针
```c++
class Solution {
public:
    string compressString(string S) {
        if (S.empty()) return "";
        int n = S.size();
        string res;
        int i = 0, j = 0;
        while(i<n)
        {
            while (j<n && S[j]==S[i])
            {
                j++;
            }
            res += S[i];
            res += to_string(j-i);
            i = j;
        }
        return res.size()>=n?S:res;
    }
};
```
