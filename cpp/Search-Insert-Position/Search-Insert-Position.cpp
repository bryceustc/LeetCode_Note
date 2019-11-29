/// Source : https://leetcode-cn.com/problems/search-insert-position
/// Author : bryce
/// Time   : 2019-11-26


// C++ Solution 1: 一次二分查找法
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int start = 0;
        int end = n;
        while (end>start)
        {
           int mid = start + (end-start)/2;
           if (nums[mid]==target)
              end = mid;
           if (nums[mid]<target)
              start = mid + 1;
           if (nums[mid]>target)
              end = mid;
        }
        return start;
    }
};


int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    int res = 0;
    res=Solution().searchInsert(nums,target);
    cout << res<< endl;
    system("pause");
    return 0;
}

// C++ Solution 2: 直接遍历
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      if (nums.empty()) return 0; 
      int n = nums.size();
      for(int i=0;i<n;i++)
      {
          if(nums[i]>=target)
          {
              return i;
          }
      }
      return n;
    }
};
