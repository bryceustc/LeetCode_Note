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
  方法一：动态规划，用一个一维数组dp[i]表示到达i位置时所剩跳力，到达i位置的跳力与i-1的剩余跳力和i-1时的值有关，二者取最大值，然后减一，因为到达位置i还需要减一个跳力，遍历nums数组中所有元素，如果dp[i]<0 则说明到达不了此处，就return false
  
  方法二：贪心算法，用reach表示能到达的最远坐标，如果reach>=n-1，表示能到达最后一个位置，遍历数组nums，i位置时，所能到达的最远距离是，reach与i+nums[i]的最大值，如果reach<i,则说明到达不了当前位置，就break，判断此时reach是否大于n-1，是则反回true，否则返回false
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
        reach = 0
        if n==0: 
            return False
        for i in range (n):
            if  i> reach or reach==n-1:
                break
            reach = max(reach,i+nums[i])
        return reach>=n-1
```


