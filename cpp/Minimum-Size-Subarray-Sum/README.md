# 题目描述:  长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

**示例：**
```
输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的连续子数组。
 ``
# 解题思路:
  滑动窗口
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(1)
  
# 代码

###  滑动窗口
```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int left = 0, right = 0;
        int total = accumulate(nums.begin(), nums.end(),0);
        if (total < s) return 0; 
        int res = n;
        while (right < n) {
            sum += nums[right++];
            if (sum < s) {
                continue;
            } else {
                while (sum >= s) {
                    sum -= nums[left];
                    left++;
                    res = min(res, right  - left +1);
                }
            }
        }
        return res;
    }
};
```
# 参考

  -  [双指针滑动窗口](https://bryceustc.github.io/2020/04/22/%E5%8F%8C%E6%8C%87%E9%92%88%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E7%AE%97%E6%B3%95%E6%80%BB%E7%BB%93/)
