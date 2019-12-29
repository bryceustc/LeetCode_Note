# 题目描述:  全排列 II

给定一个可包含重复数字的序列，返回所有不重复的全排列。

**示例 :**
```
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

  
# 解题思路:
类似全排列I的解法，因为包含重复元素，需要多进行一步判断，先将数组排序，然后多一步 (i>0&&nums[i]==nums[i-1] && nums[i-1]==0)这一步判断。
 
 当数组中有重复元素的时候，可以先将数组排序，排序以后在递归的过程中可以很容易发现重复的元素。当发现重复元素的时候，让这一个分支跳过，以达到“剪枝”的效果，重复的排列就不会出现在结果集中。

此题与全排列一的区别在于：

1、在开始回溯算法之前，对数组进行一次排序操作，这是上面多次提到的；

2、在进入一个新的分支之前，看一看这个数是不是和之前的数一样，如果这个数和之前的数一样，并且之前的数还未使用过，那接下来如果走这个分支，就会使用到之前那个和当前一样的数，就会发生重复，此时分支和之前的分支一模一样。

![DFS](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations-II/Image/DFS.png.png)


# 时间复杂度：
  O(n<sup>2</sup>)  遍历矩阵所有元素
# 空间复杂度
  O(n<sup>2</sup>)  需要一个n\*n矩阵存储元素
  
# 代码

## [C++](./Permutation-II.cpp):

###  方法一： 回溯+剪枝
```c++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        int n = nums.size();
        vector<int> visited (n,0);
        if (nums.empty())
            return res;
        sort(nums.begin(),nums.end());
        DFS(nums,0,visited,out,res);
        return res;
    }
    void DFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res)
    {
        int n = nums.size();
        if (level==n)
        {
            res.push_back(out);
            return;
        }
            
        for (int i=0;i<n;i++)
        {
            if (i>0 && nums[i]==nums[i-1] && visited[i-1]==0) //判断num[i]==nums[i-1]前提是有序，相同的数字才回相邻
                continue;
            if (visited[i]==1)
                continue;
            visited[i]=1;
            out.push_back(nums[i]);
            DFS(nums,level+1,visited, out, res);
            out.pop_back();
            visited[i]=0;
        }
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Permutation-II/Permutation-II.py)
###  方法一：回溯+剪枝
```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        out = []
        n = len(nums)
        if n==0 :
            return res
        
        visited = [ 0 for i in range(n)]
        nums= sorted(nums)
        self.DFS(nums,0,visited,out,res)
        return res
    def DFS(self,nums:List[int],level:int,visited:List[int],out:List[int],res:List[List[int]]):
        n = len(nums)
        if level == n:
            res.append(out[:])
            return
        for i in range (0,n):
            if visited[i] ==1:
                continue
            if i>=1 and nums[i]==nums[i-1] and visited[i-1]==0:
                continue
            visited[i]=1
            out.append(nums[i])
            self.DFS(nums,level+1,visited,out,res)
            out.pop()
            visited[i]=0
```


# 参考

  -  [回溯+剪枝](https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/)

