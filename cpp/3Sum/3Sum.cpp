/// Source : https://leetcode-cn.com/problems/3sum/
/// Author : bryce
/// Time   : 2019-11-06

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());//首先对nums进行从小到大排序
        
        for (int k = 0; k < nums.size(); k++) 
        {
            while (k != 0 && k < nums.size() && nums[k] == nums[k-1] )  //枚举第一个不重复数字
                k++;
            int l = k + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[k] + nums[l] + nums[r] == 0)
                {
                    res.push_back({nums[k],nums[l],nums[r]});
                    while (l < r && nums[l] == nums[l+1]) //后两个不重复数字
                        ++l;
                    while (l < r && nums[r] == nums[r-1])
                        --r;
                    ++l;--r;
                }
                else if (nums[k] + nums[l] + nums[r] < 0)
                    ++l;
                else 
                    --r;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = Solution().threeSum(nums);
    return 0;
}
