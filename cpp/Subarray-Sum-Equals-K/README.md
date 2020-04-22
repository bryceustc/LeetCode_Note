# 题目描述:  和为K的子数组

给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

**示例 :**
```
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
```

# 解题思路:
前缀和+哈希表

前缀和，最关键的思路是想到将连续的子序列转换为从头开始计算的两个队列和之差


# 时间复杂度：
 O(n)
# 空间复杂度
  O(n)
# 代码

### 前缀和+哈希表
```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        unordered_map<int,int> m;
        // 注意这里前缀和多了一个0，防止漏掉数组的前缀和刚好等于k的情况
        // 前缀和，最关键的思路是想到将连续的子序列转换为从头开始计算的两个队列和之差
        // sum = nums[0] + nums[1]+...nums[i]
        // nums[0]+..nums[j] = sum-k;
        // nums[j+1] +...+ nums[i] = k
        m[0]=1;
        int sum = 0;
        for (int i=0;i<n;i++)
        {
            sum+=nums[i];
            res += m[sum-k];
            m[sum]++;
        }
        return res;
    }
};
```
