# 题目描述: 组合总和

给定一个**无重复元素**的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target *的组合。

candidates 中的每个数字在每个组合中只能使用一次。。

**说明：**

  - 所有数字（包括 target）都是正整数。
  - 解集不能包含重复的组合。

**示例 1:**
```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

**示例 2:**
```
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
```
  
# 解题思路:
  
  这道题跟之前那道 Combination Sum 本质没有区别，只需要改动一点点即可，之前那道题给定数组中的数字可以重复使用，而这道题不能重复使用，只需要在之前的基础上修改两个地方即可，首先在递归的 ``for`` 循环里加上``if (i > start && num[i] == num[i - 1]) continue;`` 这样可以防止 ``res`` 中出现重复项，然后就在递归调用DFS里面的参数换成 ``i+1``，这样就不会重复使用数组中的数字了

# 时间复杂度：
  O(n2<sup>n</sup>)
  
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Combination-Sum-II.cpp):
### 方法一： DFS递归法
```c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(),candidates.end());  // 排序
        if (candidates.empty())
            return res;
        DFS(candidates, target, 0, out, res);
        return res;
    }
    
    void DFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res)
    {
        if (target < 0) return;
        if (target == 0)
        {
            res.push_back(out);
            return;
        }
        int n = candidates.size();
        for (int i = start; i<n; i++)
        {
            if (i-1>=start && candidates[i-1]==candidates[i])  // 先判断是否大于start，即是否越界，这两个顺序不能交换，交换就溢出
                continue;
            out.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i+1, out, res);
            out.pop_back();
        }
    }
};
```



## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Combination-Sum-II/Combination-Sum-II.py)
### 方法一： DFS递归法
```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        out = []
        self.DFS(candidates, target, 0, out, res)
        return res
    def DFS(self, candidates: List[int], target: int, start: int, out: List[int], res: List[List[int]]):
        if target < 0: return
        if target == 0:
            res.append(out[:])
            return
        n = len(candidates)
        for i in range (start,n):
            out.append(candidates[i])
            self.DFS(candidates,target-candidates[i],i,out,res)
            out.pop()  ## out.pop(-1) or del out[-1]
```
