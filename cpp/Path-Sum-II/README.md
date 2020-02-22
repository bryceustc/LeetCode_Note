# 题目描述:  路径总和 II

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

**说明** 
叶子节点是指没有子节点的节点。

**示例 :**
给定如下二叉树，以及目标和 sum = 22，
```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
```
返回：
```
[
   [5,4,11,2],
   [5,8,4,5]
]
```
  
# 解题思路:

dfs递归

  思路： 
  - 递归前序遍历树， 把结点加入路径。
  - 若该结点是叶子结点则比较当前路径和是否等于期待和。
  - 弹出结点，每一轮递归返回到父结点时，当前路径也应该回退一个结点
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Path-Sum-II.cpp):

###  
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =0;
        unordered_map<int,int> map;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int i=0;i<n;i++)
        {
            if (map[nums[i]]==1)
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Path-Sum-II/Path-Sum-II.py)
###  
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_table = {}
        for num in nums:
            try:
                hash_table.pop(num)
            except:
                hash_table[num] = 1
        res = hash_table.popitem()[0]  ## Python 字典 popitem() 方法随机返回并删除字典中的最后一对键和值。如果字典已经为空，却调用了此方法，就报出KeyError异常。
        return res
```
# 参考
  -  [剑指offer_34题——二叉树中和为某一值的路径](https://github.com/bryceustc/CodingInterviews/blob/master/PathInTree/README.md)
