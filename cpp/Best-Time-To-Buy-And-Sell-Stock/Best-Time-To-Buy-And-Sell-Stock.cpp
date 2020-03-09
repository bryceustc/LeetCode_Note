class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<=1) return 0;
        int res = 0;
        int min_price = prices[0];
        for (int i=0;i<n;i++)
        {
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return res;
    }
};
