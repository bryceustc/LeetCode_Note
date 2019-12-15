# 题目描述:  跳跃游戏

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。


**示例 1:**
```
输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
```

**示例 2:**
```
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
```

  
# 解题思路:
  1. 首先设定上下左右边界

  2. 其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
  
  3. 判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
  
  4. 若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
  
  5. 不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
# 时间复杂度：
  O(n) 
# 空间复杂度
  动态规划：O(n) 需要一维数组 ``dp`` 存储信息。
  贪心算法：O(1)
  
# 代码

## [C++](./Jump-Game.cpp):

###  方法一： 动态规划
```c++
class Solution {
public:
bool canJump(vector<int>& nums) 
{
    int n=nums.size();
    if (nums.empty())  return 0;
    vector<int> dp(n,0);
    for (int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1],nums[i-1])-1;
        if (dp[i]<0) return 0;
    }
    return 1;
}
};
```

###  方法二： 贪心算法
```c++
class Solution {
public:
bool canJump(vector<int>& nums) 
{
        int reach=0;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
              if (i>reach || reach==n-1) break;
              reach = max(reach,i+nums[i]);
        }
        return reach>=n-1;
}
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Jump-Game/Jump-Game.py)
###  方法一：动态规划
```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n==0: 
            return False
        dp=[0 for _ in range(n)]
        for i in range (1,n):
            dp[i] = max(dp[i-1],nums[i-1])-1
            if dp[i]<0:
                return False
        return True
```
### 方法二 ： 贪心算法
```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n==0: 
            return False
        dp=[0 for _ in range(n)]
        for i in range (1,n):
            dp[i] = max(dp[i-1],nums[i-1])-1
            if dp[i]<0:
                return False
        return True
```


