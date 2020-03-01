class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = -1;
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        int n = dp.size();
        for (int i = 0;i<n;i++)
        {
            for (int coin : coins)
            {
                // 只有i>coin(面值)的时候才有解
                if (i - coin < 0)
                {
                    continue;
                }
                dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        if (dp[amount] == amount+1)
            return -1;
        else
            res = dp[amount];
        return res;
    }
};
