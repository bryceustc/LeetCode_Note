# 题目描述:  跳跃游戏 II

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。

**示例 1:**
```
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```

  
# 解题思路:
  贪心算法
# 时间复杂度：
  O(n) 
# 空间复杂度
  O(1)
  
# 代码

###  贪心算法
```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // 记录能够到达的最远距离
        int reach = 0;
        // 记录上一步step跳的最远距离
        int end = 0;
        int res =0;
        for (int i=0;i<n-1;i++)
        {
            reach = max(reach, i+nums[i]);
            if (reach>=n-1) return res+1;
            // 当到达上一步的最远距离的时候，那么意味着我们需要进行一次新的起跳，那么步数 + 1
            // 并且更新最远距离
            if (i==end)
            {
                end = reach;
                res++;
            }
        }
        return res;
    }
};
```