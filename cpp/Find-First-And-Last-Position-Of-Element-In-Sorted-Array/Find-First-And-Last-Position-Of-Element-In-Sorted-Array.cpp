/// Source : https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
/// Author : bryce
/// Time   : 2019-11-25


// C++ Solution 1: 两次二分查找法
#include <iostream>
#include <vector>
using namespace std;

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


int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res;
    res=Solution().searchRange(nums,target);
    int m = res.size();
    for (int i = 0; i < m; i++)
    {
        cout << res[i]<< endl;
    }
    system("pause");
    return 0;
}

/// C++ Solution 2: 线性扫描，两次遍历，寻找左右边界。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res = {-1,-1};
      int n = nums.size();
      if (nums.empty()) return res; 
      for(int i=0;i<n;i++)
      {
          if(nums[i]==target)
          {
              res[0] = i;
              break;
          }
      }
      if (res[0]==-1) return res;
      for (int j=n-1;j>=0 ;j--)
      {
          if (nums[j]==target) 
          {
              res[1] =j;
              break;
          }
      }
      return res;
    }
};
