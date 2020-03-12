# 题目描述:  最大正方形

在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

**示例 :**
```
输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
```

# 解题思路:
  dp

# 时间复杂度：
  O(n)
# 空间复杂度
O(n)
  
# 代码

### dp
```c++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int i=0, j=0;
        int res = 1;
        while (j<n-1)
        {
            if (nums[j+1] > nums[j])
            {
                j++;
                res = max(res, j-i+1);
            }
            else
            {
                j++;
                i = j;
            }
        }
        return res;
    }
};
```
