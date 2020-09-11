## 题目描述 组合总和 III


找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

- 所有数字都是正整数。
- 解集不能包含重复的组合。 


示例：
```
输入: k = 3, n = 7
输出: [[1,2,4]]

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
```

思路：标准的dfs模板

```c++
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0) return res;
        dfs(n,0,1,k);
        return res;
    }
    void dfs(int num, int u, int start, int k) {
        if (num < 0) return;
        if (num==0 && u==k) {
            res.push_back(out);
            return;
        }
        for (int i = start; i <= 9; i++) {
            out.push_back(i);
            dfs(num - i, u+1, i + 1, k);
            out.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<int> out;
};
```
