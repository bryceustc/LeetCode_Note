/// Source : https://leetcode-cn.com/problems/find-the-duplicate-number/
/// Author : bryce
/// Time   : 2019-12-2

#include<vector>
#include<iostream>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());  //排序更改了原数组
        int n = nums.size();
        for (int i=1;i<n+1;i++)
        {
            if (nums[i]==nums[i-1])
            {
                res = nums[i];
            }
        }
        return res;

        
        unordered_map<int,int> record;  //空间复杂度不满足要求
        for(auto i : nums)
        {
            record[i]++;
            if (record[i]>1)
            {
                res= i;
                break;
            }
        }
        return res;

        int n = nums.size()-1;
        int start = 1;
        int end = n;
        while (end > start)
        {
            int m = 0;
            int mid = start + (end-start)/2;
            for (int i=0;i<n+1;i++)
            {
                if (nums[i]>=start && nums[i]<=mid)
                {
                    m++;
                }
                // for (auto num : nums)
                // {
                //     if (num <=mid && num >=start)
                //         m++;
                // }
            }
            if (m>mid-start+1)
            {
                end = mid;
            }
            else
            {
                start = mid +1;
            }
        }
        return start;
    }
};


int main()
{
    vector<int> nums = {1,4,4,2,4};
    int res;
    cout<<Solution().findDuplicate(nums)<<endl;
    system("pause");
    return 0;
}
