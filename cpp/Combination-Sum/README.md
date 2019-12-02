# 题目描述: 组合总和

给定一个**无重复元素**的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target *的组合。

candidates 中的数字可以无限制重复被选取。

**说明：**

  - 所有数字（包括 target）都是正整数。
  - 解集不能包含重复的组合。

**示例 1:**
```
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
```

**示例 2:**
```
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```
  
# 解题思路:
  
  像这种结果要求返回所有符合要求解的题十有八九都是要利用到**递归回溯**，而且解题的思路都大同小异，相类似的题目有 Path Sum II，Subsets II，Permutations，Permutations II，Combinations 等等，如果仔细研究这些题目发现都是一个套路，都是需要另写一个递归函数，这里我们新加入三个变量，start 记录当前的递归到的下标，out 为一个解，res 保存所有已经得到的解，每次调用新的递归函数时，此时的 target 要更新，减去当前数组的的数。
  
  针对示例 1：
  ```
  输入: candidates = [2, 3, 6, 7]，target = 7，所求解集为: [[7], [2, 2, 3]]
  ```
  以 target = 7 为根结点，每一个分支做减法。减到 0或者负数的时候，剪枝。其中，减到 0 的时候结算，这里 “结算” 的意思是添加到结果集。
  
  ![DFS](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Combination-Sum/Images/DFS.png)
  
  说明：

  1、一个蓝色正方形表示的是 “尝试将这个数到数组 candidates 中找组合”，那么怎么找呢？挨个减掉那些数就可以了。

  2、在减的过程中，会得到 0 和负数，也就是被我标红色和粉色的结点：

  - 得到 0 是我们喜欢的，从 0 这一点向根结点走的路径（很可能只走过一条边，也算一个路径），就是一个组合，在这一点要做一次结算（把根结点到0所经过的路     径，加入结果集）。

  - 得到负数就说明这条路走不通，没有必要再走下去了。
  
  总结一下：在减的过程中，得到 0 或者负数，就没有必要再走下去，所以这两种情况就分别表示成为叶子结点。此时递归结束，然后要发生回溯。

  画出图以后，结果有 4 个 0，对应的路径是 ``[[2, 2, 3], [2, 3, 2], [3, 2, 2], [7]]``，而示例中的解集只有 ``[[7], [2, 2, 3]]``，很显然，分析出现了问题。问题是很显然的，结果集出现了重复。重复的原因是:
  ```
  后面分支的更深层的边出现了前面分支低层的边的值。
  ```
  可以对数组进行排序或者按照顺序读取，实现剪枝工作，消除重复解集。
  

# 时间复杂度：
  O(n2<sup>n</sup>)
  
# 代码

## [C++](./Combination-Sum.cpp):
### 方法一： DFS递归法
```c++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
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
            out.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};
```



## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Combination-Sum/Combination-Sum.py)
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
