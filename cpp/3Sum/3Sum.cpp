/// Source : https://leetcode-cn.com/problems/3sum/
/// Author : bryce
/// Time   : 2019-11-06
/*
一重循环k无重复枚举第一个数字，然后接下来采用两头向里寻找的方式无重复的构造剩下的两个数字，具体在循环中：

初始化l为st+1，r为n-1。
当l<r时，如果当前nums[l] + nums[r] == target，则增加答案并同时向后无重复移动l，向前无重复移动r；
否则根据nums[l] + nums[r]与target的关系判断移动l还是移动r。
*/


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
