class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n,0);
        
        for (int i=0;i<n;i++)
        {
            int a = candies[i];
            int b = a + extraCandies;
            int c = *max_element(candies.begin(),candies.end());
            if (b>=c) res[i] =1;
        }
        return res;
    }
};
