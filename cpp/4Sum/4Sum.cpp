/// Source : https://leetcode-cn.com/problems/4sum/
/// Author : bryce
/// Time   : 2019-11-09

/*
LeetCode 中关于数字之类似的还有Two Sum ，3Sum ，3Sum Closest，解法的思路跟3Sum 基本没啥区别，就是多加了一层 for 循环，其他的都一样.
使还有一种解法是为了避免重复项，STL 中的 TreeSet，其特点是不能有重复，如果新加入的数在 TreeSet 中原本就存在的话，插入操作就会失败，这
样能很好的避免的重复项的存在。
*/

// C++ Solution 1 : 多一层for 循环
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (n < 3) return res;
        for (int i = 0;i < n-3;i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;   //continue是结束单次循环，继续执行下一次循环
            for (int j = i+1; j < n-2; j++)
            {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int l = j + 1; 
                int r = n -1;
                while (l<r)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target)
                    {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while (l<r && nums[l] == nums[l-1]) ++l;
                        while (l<r && nums[r] == nums[r+1]) --r;
                        ++l;--r;
                    }
                    if (sum < target) ++l;
                    if (sum > target) --r;
                }
            }
        }
        return res;
            
    }
};


//C++ Solution 2:  使用STL 中的 TreeSet
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) {
            for (int j = i + 1; j < int(nums.size() - 2); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
