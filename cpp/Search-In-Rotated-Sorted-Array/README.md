# 题目描述:  搜索旋转排序数组

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。


**示例 :**
```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```

# 解题思路:
有序数组一半考虑二分查找

1. 右半段是有序的，nums[mid] < nums[end]

2. 左半段是有序的,nums[mid] >= nums[end]

3. 发现规律 如果中间的数小于最后边的数，则右半段是有序的，否则是左半段是升序的，然后根据target判断是在左半段，还是右半段

4.然后再在左半段或者右半段进行二分法搜索
# 时间复杂度：
O(logn) 
# 空间复杂度
O(1)
  
# 代码
### 二分查找
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) return -1;
        int start = 0;
        int end = n-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<nums[end])   // 后半段有序
            {
                if (nums[mid]< target && nums[end]>=target)
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            else if (nums[mid]>=nums[end])  // 前半段有序
            {
                if (nums[start]<=target && nums[mid]>target)
                {
                    end  = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }
        }
        return -1;
    }
};
```
### 利用find函数
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int res = find(nums.begin(),nums.end(), target) - nums.begin();    // find失败会返回nums.end()
        return res==n?-1:res;
    }
};
```
