

// Solution 1:

class Solution {
public:
    int maxSubArray(vector<int> &nums){
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int res = INT_MIN;
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




// Solution 3:
