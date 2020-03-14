# 题目描述:  俄罗斯套娃信封问题

给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

**说明:**
不允许旋转信封。

**示例 :**
```
输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
```

# 解题思路:

  dp
  
  1、**定义状态**：dp[i]表示到第i个信封为止，有多少个信封能组成一组“俄罗斯套娃”信封
  
  2、**状态转移方程**
  
在索引 i 之前严格小于 nums[i] 的所有状态中的最大者 +1

0<j<i

所以在$envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]$写出状态转移方程：
$$
dp[i]=max(dp[i], dp[j]+1) 
$$

3、**初始状态：**

dp[i] 所有元素置 1，含义是每个元素都至少可以单独成为一个俄罗斯信封，此时长度都为 1。

4、**返回值**

返回 dp 列表最大值，即为结果

# 时间复杂度：
  O(n^2)
# 空间复杂度
O(n)
  
# 代码

### dp
```c++
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp (n,1);
        int res = 0;
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        for (int i=0;i<n;i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};
```
