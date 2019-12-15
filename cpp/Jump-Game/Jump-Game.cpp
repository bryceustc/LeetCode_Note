// C++ Solution 1: 动态规划
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


// C++ Solution 2: 贪心算法
class Solution {
public:
bool canJump(vector<int>& nums) 
{
        int reach=0;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
              if (i>reach || reach==n-1) break;
              reach = max(reach,i+nums[i]);
        }
        return reach>=n-1;
}
};
