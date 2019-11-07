/// Source : https://leetcode-cn.com/problems/3sum-closest/
/// Author : bryce
/// Time   : 2019-11-07


/*
与上一题三个数求和类似，需要定义一个变量记录差的绝对值，再将数组排序，然后开始遍历数组，先确定一个数，
然后剩下两个从左右两端，滑动来寻找另外两个数，每确定两个数，求出三个数之和,然后算和给定值的差的绝对值存在新的变量中，然后在和之前比较更新差值和结果
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int res = nums[0] + nums[1] + nums[2];
      int diff = abs(res - target);
      int n = nums.size();
      sort(nums.begin(),nums.end());
      for (int k = 0; k < n - 2; k++)
      {
          int i = k + 1; int j = n - 1;
          while(i < j)
          {
            int sum = nums[k] + nums[i] + nums[j];
            int newDiff = abs(sum - target);
            if (diff > newDiff)
            {
              diff = newDiff;
              res = sum;
            }
            if (sum > target)
              j--;
            else 
              i++;
          }  
      }
      return res;
    }
};
