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
  
  像这种结果要求返回所有符合要求解的题十有八九都是要利用到**递归回溯**，而且解题的思路都大同小异，相类似的题目有 Path Sum II，Subsets II，Permutations，Permutations II，Combinations 等等，如果仔细研究这些题目发现都是一个套路，都是需要另写一个递归函数，这里我们新加入三个变量，start 记录当前的递归到的下标，out 为一个解，res 保存所有已经得到的解，每次调用新的递归函数时，此时的 target 要更新，减去当前数组的的数。
  
  针对示例 1：
  ```
  输入: candidates = [2, 3, 6, 7]，target = 7，所求解集为: [[7], [2, 2, 3]]
  ```
一开始我画的图是这样的：

思路：以 target = 7 为根结点，每一个分支做减法。减到 0或者负数的时候，剪枝。其中，减到 0 的时候结算，这里 “结算” 的意思是添加到结果集。

# 时间复杂度：
  O(n2^n)
  
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
