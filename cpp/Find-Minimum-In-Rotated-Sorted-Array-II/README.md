# 题目描述:  寻找旋转排序数组中的最小值

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

**示例 1:**
```
输入: [3,4,5,1,2]
输出: 1
```

**示例 2:**
```
输入: [4,5,6,7,0,1,2]
输出: 0
```

  
# 解题思路:

使用二分查找，如果中间元素大于尾元素，``l=mid+1``，时间复杂度为O(logn)
 
# 时间复杂度：
  
  O(logn)
  
# 空间复杂度
  O(1)
  
# 代码
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + (r -l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                r--;
            }
        }
        return nums[l];
    }
};
```
