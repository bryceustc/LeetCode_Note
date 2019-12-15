class Solution {
public:
bool canJump(vector<int>& nums) 
{
    int n=nums.size();
    if (nums.empty())  return 0;
    vector<int> dp(n,0);
    for (int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1],nums[i-1])-1;
        if (dp[i]<0) return 0;
    }
    return 1;
}
};
