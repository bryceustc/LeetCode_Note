# 题目描述:  打家劫舍 III

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。


**示例 :**
```
输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
```

# 解题思路:
  动态规划：
  
  此题与198题打家劫舍类似，不过房间构成了一个环，我们需要把环拆成两个队列，一个是从0到n-1，另一个是从1到n，然后返回两个结果最大的。用两遍198题的方法就可以。
  
  1. 定义状态：dp[i][j]，表示前i间房子中，状态为j(0/1)的最大金钱数。0为不偷当前房屋，1为偷当前房屋
  
  2. 状态转移方程：
  $$
   dp[i][0] = max(dp[i-1][0], dp[i-1][1]);   
   dp[i][1] = dp[i-1][0] + nums[i];
  $$
  
  3. 初始状态：
  ```
  dp[0][0] = 0;  dp[0][1] = nums[0];
  ```
  4. 返回结果：
   ```
   res = max(dp[n-1][0], dp[n-1][1]);
   ```
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
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        vector<vector<int>> dp1(n-1, vector<int>(2,0));
        vector<vector<int>> dp2(n, vector<int>(2,0));
        dp1[0][0] = 0; dp1[0][1] = nums[0];
        dp2[1][0] = 0; dp2[1][1] = nums[1];
        for (int i=1;i<n-1;i++)
        {
            dp1[i][0] = max(dp1[i-1][0], dp1[i-1][1]);
            dp1[i][1] = dp1[i-1][0] + nums[i];
        }
        int res1 = max(dp1[n-2][0], dp1[n-2][1]);
        for (int i=2;i<n;i++)
        {
            dp2[i][0] = max(dp2[i-1][0], dp2[i-1][1]);
            dp2[i][1] = dp2[i-1][0] + nums[i];
        }
        int res2 = max(dp2[n-1][0], dp2[n-1][1]);
        return max(res1, res2);
    }
};
```
###  dp简化版
```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        int dp1_0 = 0;
        int dp1_1 = nums[0];
        int dp2_0 = 0;
        int dp2_1 = nums[1];
        for (int i=1;i<n-1;i++)
        {
            int tdp1_0 = max(dp1_0, dp1_1);
            int tdp1_1 = dp1_0 + nums[i];
            dp1_0 = tdp1_0;
            dp1_1 = tdp1_1;
        }
        int res1 = max(dp1_0, dp1_1);
        for (int i=1;i<n-1;i++)
        {
            int tdp2_0 = max(dp2_0, dp2_1);
            int tdp2_1 = dp2_0 + nums[i+1];
            dp2_0 = tdp2_0;
            dp2_1 = tdp2_1;
        }
        int res2 = max(dp2_0, dp2_1);
        return max(res1, res2);
    }
};
```
