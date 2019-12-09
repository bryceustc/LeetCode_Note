

// Solution 1:

class Solution {
public:
    int maxSubArray(vector<int> &nums){
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值 
        // 或者不用初始化为理论的最小值
        //int res = INT_MIN;
        int res = nums[0];
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            int sum = 0;
            for (int j=i;j<n;j++)
            {
                sum+=nums[j];
                res = max(res,sum);
            }
        }
        return res;
    }
};


// Solution 2:
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int res = nums[0];
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i=1;i<n;i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int res = nums[0];
        int n = nums.size();
        int sum = 0;
        for (int i=0;i<n;i++)
        {
            if (sum>0)
            {
                sum+=nums[i];
            }
            else
            {
                sum = nums[i];
            }
            res = max(res,sum);
        }
        return res;
    }
};


// Solution 3:
