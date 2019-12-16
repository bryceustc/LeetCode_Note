# 题目描述:  合并区间

给出一个区间的集合，请合并所有重叠的区间。

**示例 1:**
```
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

**示例 2:**
```
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

  
# 解题思路:

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



