给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:
```
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

```c++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k || k <=0 ) return res; 
        dfs(n, k, 1);
        return res;
    }
    void dfs(int n, int k, int start) {
        if (path.size() == k) {
            res.push_back(path);
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i+1);
            path.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};
```
