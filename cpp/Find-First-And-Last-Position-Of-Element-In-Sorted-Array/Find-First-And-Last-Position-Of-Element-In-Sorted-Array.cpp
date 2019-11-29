/// Source : https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
/// Author : bryce
/// Time   : 2019-11-25


// C++ Solution 1: 两次二分查找法
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res = {-1,-1};
      int n = nums.size();
      if (nums.empty()) return res;
      int start = 0;
      int end = n;
      while (end > start)   // 寻找左边界，搜索区间为左闭右开
      {
        int mid = start + (end - start)/2;
        if (nums[mid]==target)
        {
            end = mid;
        }
        if (nums[mid]<target)
        {
            start = mid + 1;
        }
        if (nums[mid]>target)
        {
            end = mid;
        }
      }
      if (start==n || nums[start]!=target) return res;
      res[0] = start;
      start = 0;
      end = n;
      while(end > start) //寻找右边界，搜索区间为左开右闭
      {
        int mid = start + (end - start)/2;
        if (nums[mid]==target) 
        {
            start = mid + 1;
        }
        if (nums[mid] < target)
        {
            start = mid + 1;
        }
        if (nums[mid] > target)
        {
            end = mid;
        }
      }
      res[1] = end - 1;
      return res;
    }
};
