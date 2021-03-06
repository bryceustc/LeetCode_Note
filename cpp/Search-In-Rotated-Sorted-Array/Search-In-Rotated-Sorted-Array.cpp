/// Source : https://leetcode-cn.com/problems/merge-two-sorted-lists/
/// Author : bryce
/// Time   : 2019-11-24

/*
思路:
1.这道题让在旋转数组中搜索一个给定值，若存在返回坐标，若不存在返回 -1。我们还是考虑二分搜索法，但是这道题的难点在于不知道原数组在哪旋转了，还
  是用题目中给的例子来分析，对于数组 [0 1 2 4 5 6 7] 共有下列七种旋转方法 ()表示中点之前或者之后一定为有序的：
  0　　1　　2　　 (4)　　5　　6　　7   // 右半段是有序的，nums[mid] < nums[end]

  7　　0　　1　　 (2)　　4　　5　　6

  6　　7　　0　　 (1)　　2　　4　　5

  5　　6　　7　　 (0)　　1　　2　　4 

  4　　5　　6　　 (7)　　0　　1　　2  // 左半段是有序的,nums[mid] > nums[end]

  2　　4　　5　　 (6)　　7　　0　　1

  1　　2　　4　　 (5)　　6　　7　　0
2.根据列出的例子，发现规律，如果中间的数小于最后边的数，则右半段是有序的，否则是左半段是升序的，然后根据target判断是在左半段，还是右半段
3.然后再在左半段或者右半段进行二分法搜索

时间复杂度：
要求为O(logn)
空间复杂度：
O(1)。
*/

// C++ Solution 1: (二分查找)
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      int n = nums.size();
      int start = 0;
      int end = n-1;
      while (end >= start)
      {
        int mid = start + (end-start)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < nums[end])
        {
          if (nums[mid]<target && nums[end] >= target)
          {
            start = mid +1;
          }
          else
          {
            end = mid - 1;
          }
        }
        else
        {
          if (nums[start]<=target && nums[mid]>target)
          {
            end = mid - 1;
          }
          else
          {
            start = mid + 1;
          }
        }
      }
      return -1;
    }
};

/*
也可以nums[mid]与nums[start]比较，若大于等于nums[start]左半段有序，否则右半段是有序的
*/


// C++ Solution 2: (二分查找,nums)
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      int n = nums.size();
      int start = 0;
      int end = n-1;
      while (end>=start)
      {
        int mid = start + (end-start)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid]>=nums[start])
        {
          if (nums[start]<=target && nums[mid] > target)
          {
            end = mid - 1;
          }
          else
          {
            start = mid + 1;
          }
        }
        else
        {
          if (nums[mid]<target && nums[end] >= target)
          {
            start = mid + 1;
          }
          else
          {
            end = mid - 1;
          }
        }
      }
      return -1;
     }
  };
