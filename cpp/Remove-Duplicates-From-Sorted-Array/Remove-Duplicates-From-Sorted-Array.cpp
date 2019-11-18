/// Source : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
/// Author : bryce
/// Time   : 2019-11-17

/*
思路(双指针移动)：
1. 如果nums为空，直接返回0
2. 初始化k = 0,从i=1开始遍历整个数组，如果nums[k]不等于nums[i]，说明没有遇到重复元素，就是新元素，令nums[++k] = nums[i]
3. 返回res = k+1,
时间复杂度：
遍历一遍数组，时间复杂度为O(n)
*/
// C++ Solution 1:(for 循环)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int res = 0;
      int n = nums.size();
      int k = 0;
      if (nums.empty()) return res;
      for (int i = 1; i<n;i++)
      {
        if (nums[k] != nums[i])
          nums[++k] = nums[i];
      }
      res = k+1;
      return res;
    }
};
/*
使用l,r左右两个指针来记录遍历的坐标
1. 开始两个指针指向同一元素
2. 如果左指针和右指针相等，向后移动右指针
3. 如果不相等，则同时向后移动左右指针
4. 当右指针走完整个数组后，左指针当前的坐标加1就是数组中不同数字的个数
*/

// C++ Solution 2: (双指针)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int l = 0, r = 0, res = 0;
      if (nums.empty()) return res;
      int n = nums.size();
      while(l<=r)
      {
        if (nums[r] == nums[l]) 
          r++;
        else
        {
          l++;
          nums[l] = nums[r];
          r++;
        }
      }
      res = l + 1;
      return res;
    }
};
