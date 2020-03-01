class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        res = -1
        dp = [amount+1 for _ in range(amount+1)]
        dp[0] = 0
        n = len(dp)
        for i in range(n):
            for coin in coins:
                if i < coin:
                    continue
                dp[i] = min(dp[i], dp[i-coin]+1)
        if dp[amount]==amount+1:
            res = -1
        else:
            res = dp[amount]
        return res
