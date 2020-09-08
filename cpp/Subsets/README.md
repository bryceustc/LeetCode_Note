### 题目描述 子集

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:
```
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```
### 解题思路
利用dfs模板，注意不用使用vis数组，因为每次都会把更新start ，后边肯定是没遍历过的，不需要vis数组。此题跟77题很像

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return res;
        dfs(n, nums, 0);
        return res;
    }
    void dfs(int n, vector<int> &nums, int start) {
        res.push_back(out);
        for (int i = start ; i < n; i++) {
            out.push_back(nums[i]);
            dfs(n, nums, i+1);
            out.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<int> out;
};
```
利用数学归纳法，找出递归规律
```c++
vector<vector<int>> subsets(vector<int>& nums) {
    // base case，返回一个空集
    if (nums.empty()) return {{}};
    // 把最后一个元素拿出来
    int n = nums.back();
    nums.pop_back();
    // 先递归算出前面元素的所有子集
    vector<vector<int>> res = subsets(nums);

    int size = res.size();
    for (int i = 0; i < size; i++) {
        // 然后在之前的结果之上追加
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}
```
