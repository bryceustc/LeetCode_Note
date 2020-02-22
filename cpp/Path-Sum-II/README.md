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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> path;
        dfs(root, res, path, sum);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>> &res, vector<int> &path, int sum)
    {
        if (root == NULL)
            return;
        path.push_back(root->val);
        bool isLeaf = (root->left == NULL) && (root->right == NULL);
        if (sum == root->val && isLeaf)
        {
            res.push_back(path);
        }
        dfs(root->left, res, path, sum - root->val);
        dfs(root->right, res, path,sum - root->val);
        path.pop_back();
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Path-Sum-II/Path-Sum-II.py)
###  
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.res = []
        self.path = []
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root is None:
            return self.res
        self.dfs(root, self.path, sum)
        return self.res
    def dfs(self, root, path, sum):
        if root is None:
            return
        self.path.append(root.val)
        if sum == root.val and (root.left is None and root.right is None):
            self.res.append(self.path[:])
        self.dfs(root.left, self.path, sum - root.val)
        self.dfs(root.right, self.path, sum - root.val)
        self.path.pop()
```
# 参考
  -  [剑指offer_34题——二叉树中和为某一值的路径](https://github.com/bryceustc/CodingInterviews/blob/master/PathInTree/README.md)
