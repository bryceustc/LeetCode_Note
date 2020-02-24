# 题目描述:  路径总和

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

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
返回: 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
  
# 解题思路:

dfs递归

利用递归，遍历整棵树：如果当前节点不是叶子，对它的所有孩子节点，递归调用 hasPathSum 函数，其中 sum 值减去当前节点的权值；如果当前节点是叶子，检查 sum 值是否为 0，也就是是否找到了给定的目标和。

# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Path-Sum.cpp):
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
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        if (root == NULL)
            return res;
         helper(root, sum, res);
        return res;
    }
    void helper(TreeNode* root, int expectNumber, bool &res)
    {
        if (root == NULL)
            return;
        bool isLeaf = root->left == NULL && root->right == NULL;
        if (expectNumber == root->val && isLeaf)
        {
            res = true;
        }
        helper(root->left, expectNumber-root->val, res);
        helper(root->right, expectNumber-root->val, res);
    }
};
```
### 简洁版
```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL)
            return false;
        sum -= root->val;
        bool isLeaf = (root->left==NULL) && (root->right==NULL);
        if (isLeaf)
        {
            return sum==0;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Path-Sum/Path-Sum.py)
###  
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        isLeaf = (root.left==None) and (root.right==None)
        sum -= root.val
        if isLeaf:
            return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)
```
# 参考
  -  [剑指offer-34题——二叉树中和为某一值的路径](https://github.com/bryceustc/CodingInterviews/blob/master/PathInTree/README.md)
