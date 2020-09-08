### 题目描述 子集

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:
```
输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```
### 解题思路
这种有重复的元素，一般套路是先排序，然后在dfs循环中再去判断。

```c++
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return res;
        int n  = nums.size();
        // 注意要先排序
        sort(nums.begin(), nums.end());
        dfs(nums, n, 0);
        return res;
    }
    void dfs(vector<int> &nums, int n, int start) {
        res.push_back(out);
        for (int i = start ; i < n; i++) {
            // 关键点
            if (i > start && nums[i] == nums[i-1]) continue;
            out.push_back(nums[i]);
            dfs(nums, n, i + 1);
            out.pop_back();
        }
    }
private:
    vector<int> out;
    vector<vector<int>> res;
};
```
