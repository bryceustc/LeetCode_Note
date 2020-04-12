# 题目描述:  鸡蛋掉落

你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。

每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。

你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。

每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。

你的目标是确切地知道 F 的值是多少。

无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

**示例 :**
```
输入：K = 1, N = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
```

# 解题思路:
  动态规划：
  
  1. 定义状态：dp[i][k]，表示一共有 i 层楼的情况下，使用 k 个鸡蛋的最少实验的次数
  
  2. 状态转移方程：
  $$
   dp[i][k]=\min _{1 \leq j \leq i}(\max (d p[j-1][k-1], dp[i-j][k])+1)
  $$
  
  3. 初始状态：
  ```
  dp[i][1] = i; // 只有一个鸡蛋的时候，只能一层一层的扔
  ```
  4. 返回结果：
   ```
   dp[N][K];
   ```
   5. 考虑状态压缩：
   ```
   int tdp_0 = max(dp_0, dp_1);
   tdp_1 = dp_0 + nums[i];
   dp_0 = tdp_0;
   dp_1 = tdp_1;
   ```
# 时间复杂度：
  1. $O(N^2K)$
  
  2. $O(N^2K)$
# 空间复杂度
  1. $O(NK)$
  
  2: O(1)
  
# 代码
### dp（超时）
```c++
class Solution {
public:
    int superEggDrop(int K, int N) {
        // 定义状态：dp[i][k]表示一共有 i 层楼的情况下，使用 k 个鸡蛋的最少实验的次数
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        // 初始化dp数组
        for (int i = 0; i <= N; i++) dp[i][1] = i; // 只有一个鸡蛋的时候，只能一层一层的扔

        for (int i = 1; i <= N; i++) 
        {
            for (int k = 2; k <= K; k++) 
            {
                // 状态转移方程
                int res = i; 
                for (int j = 1; j <= i; j++) 
                {
                    // 碎了，就需要往低层继续扔：层数少 1 ，鸡蛋也少 1
                    // 不碎，就需要往高层继续扔：层数是当前层到最高层的距离差，鸡蛋数量不少
                    // 两种情况都做了一次尝试，所以加 1
                    res = min(res , max(dp[j-1][k-1], dp[i-j][k]) + 1);
                }
                dp[i][k] = res;
            }
        }
        return dp[N][K];
    }
};
```
###  dp考虑状态压缩
```c++
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n==1) return nums[0];
        int dp_0 = 0;
        int dp_1 = nums[0];
        for (int i=1;i<n;i++)
        {
            int tdp_0 = max(dp_0, dp_1);
            int tdp_1 = dp_0 + nums[i];
            dp_0 = tdp_0;
            dp_1 = tdp_1;
        }
        return max(dp_0, dp_1);
    }
};
```
