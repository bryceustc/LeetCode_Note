  
/// Source : https://leetcode-cn.com/problems/two-sum/
/// Author : bryce
/// Time   : 2019-10-12

/*
思路:
暴力枚举：两重循环枚举下标 i,ji,j，然后判断 nums[i]+nums[j]nums[i]+nums[j] 是否等于target

时间复杂度：O(n^2)
空间复杂度：
O(n^2)
*/

#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;


// C++ Solution 1: (暴力枚举)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

// C++ Solution 2: (哈希表)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> record;
        for (int i = 0;i<n;i++)
        {
            int complement = target - nums[i];
            if (record.find(complement) != record.end())
            {
                res.push_back(record[complement]);
                res.push_back(i);
            }
            record[nums[i]] = i;
        }
        return res;
    }
};



void  printVec (const vector<int> & vec) {
    for (int e : vec)
        cout << e << " ";
    cout << endl;
}

int main{
    vector < int > nums = { 2,7,11,15 };
    int target = 9 ;
    vector < int > res = Solution().twoSum(nums,target)
    cout << res[0] << endl;
    return 0;
}
