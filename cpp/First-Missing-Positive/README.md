# 题目描述: 缺失的第一个正数

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

**示例 1:**
```
输入: [1,2,0]
输出: 3
```

**示例 2:**
```
输入: [3,4,-1,1]
输出: 2
```

**示例 3:**
```
输入: [7,8,9,11,12]
输出: 1
```

**说明：**

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
  
# 解题思路:
  
  

# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(n)
  
# 代码

## [C++](./First-Missing-Positive.cpp):
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



## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/First-Missing-Positive/First-Missing-Positive.py)
### 方法一： DFS递归法
```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        out = []
        candidates = sorted(candidates)
        self.DFS(candidates,target,0,out,res)
        return res
    def DFS(self,candidates: List[int], target:int, start: int, out: List[int], res: List[List[int]]):
        if target < 0:
            return
        if target == 0:
            res.append(out[:])
            return
        n = len(candidates)
        for i in range(start,n):
            if candidates[i] == candidates[i-1] and i > start:
                continue
            out.append(candidates[i])
            self.DFS(candidates,target-candidates[i],i+1,out,res)
            del out[-1]
```
# 参考
  - [C++中map，hash_map,unordered_map,unordered_set区别与联系](https://blog.csdn.net/u013195320/article/details/23046305)
