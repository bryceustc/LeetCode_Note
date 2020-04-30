# 题目描述:  寻找峰值

峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

**示例1 :**
```
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
```

**示例2 :**
```
输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
```
  
# 解题思路:
看时间复杂度要求log(n)二分法应用:

发现规律：
- 如果nums[mid] > nums[mid+1]，则在mid之前一定存在峰值元素
- 如果nums[mid] < nums[mid+1]，则在mid+1之后一定存在峰值元素
 
# 时间复杂度：
  O(log(n))
# 空间复杂度
  O(1)
  
# 代码
```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         //本题从-inf到-inf, 相邻元素必不相同
        //不可能都是-inf,只要有一个元素就一定有上坡,就一定有峰顶
        // 使用二分法找峰顶
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<end) // [start,end] 型二分法
        {
        // 虽然是闭区间上查,但用<号,所以最后退出循环时[start,start]或者[end,end]是不会查的
            int mid = start + (end-start)/2;
            if (nums[mid]>nums[mid+1])  // mid比右侧大, 峰顶在左侧或就在mid处
            {
                end = mid;
            }
            else  // mid比右侧小,峰顶在右侧[mid+1,end]
            {
                start = mid+1;
            }
        }// 退出循环时 start==end
        return start;
    }
};
```
# 参考

  -  [题解](https://leetcode-cn.com/problems/find-peak-element/solution/xun-zhao-feng-zhi-by-leetcode/)
