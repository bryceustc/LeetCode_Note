/// Source : https://leetcode-cn.com/problems/4sum/
/// Author : bryce
/// Time   : 2019-11-09

/*
用迭代来求解，遍历digits中所有的数字，建立一个临时的字符串数组temp,然后通过数字到dict中取出字符串str，然后遍历取出字符串所有字符，
再遍历当前结果res中的每一个字符串，将字符加到后面，并加入到临时字符串数组temp中。取出的字符串str遍历完成后，将临时字符串数组赋值给结果res
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i< n; i++)
        {
            while(i> 0 && i < n && nums[i] == nums[i-1])
            {
                i++;
            }

            for (int j=i+1; j < n;j++)
            {
                while(j !=i+1 && j < n && nums[j] == nums[j-1])
                {
                    j++;
                }
                int l = j+1;
                int r = n-1;
                while(l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target)
                    {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while (l < r && nums[l] == nums[l+1])
                            ++l;
                        while (l < r && nums[r] == nums[r-1])
                            --r;
                    }
                        
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                        --r;
                    else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                        ++l;
                }
            }
        }
        return res;
            
    }
};
