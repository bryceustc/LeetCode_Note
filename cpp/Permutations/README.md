# 题目描述: 全排列

给定一个**没有重复**数字的序列，返回其所有可能的全排列。

**示例 :**
```
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```
  
# 解题思路:
  返回所有结果的题目基本上都是要利用到**递归回溯**,都是一个套路，需要另写一个递归函数。此题是求全排列问题，还是用递归 DFS 来求解。这里需要用到一个 visited 数组来标记某个数字是否访问过，然后在 DFS 递归函数从的循环应从头开始，而不是从 level 开始。这里再说下 level 吧，其本质是记录当前已经拼出的个数，一旦其达到了 nums 数组的长度，说明此时已经是一个全排列了，因为再加数字的话，就会超出。还有就是，为啥这里的 level 要从0开始遍历，因为这是求全排列，每个位置都可能放任意一个数字，这样会有个问题，数字有可能被重复使用，由于全排列是不能重复使用数字的，所以需要用一个 visited 数组来标记某个数字是否使用过
  

# 时间复杂度：
  O(n2<sup>n</sup>)
  
# 代码

## [C++](./Permutations.cpp):
### 方法一： DFS递归法
```c++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<int> out;
        int n =nums.size();
        vector<int> visited(n,0);
        DFS(nums,0,visited,out,res);
        return res;
    }
    
    void DFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res)
    {
        if (level == nums.size())
        {
            res.push_back(out);
            return;
        }
        for (int i=0; i<nums.size();i++)
        {
            if (visited[i] == 1)
                continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            DFS(nums,level+1,visited,out,res);
            out.pop_back();
            visited[i] = 0;
        }        
    }
};
```



## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Permutations/Permutations.py)
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

