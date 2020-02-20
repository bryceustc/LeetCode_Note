# 题目描述:  二叉树的前序遍历

给定一个二叉树，返回它的 *前序* 遍历。

**示例：**
```
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
```

# 解题思路:
递归与迭代两种方法

方法一：递归


# 时间复杂度：
  O(n) 
# 空间复杂度
  O(n)
# 代码

## [C++](./Binary-Tree-Preorder-Traversal.cpp):

###  递归
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root, vector<int> &res)
    {
        if (root==NULL)
            return;
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
    }
};
```

###  迭代
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root, vector<int> &res)
    {
        if (root==NULL)
            return;
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Binary-Tree-Preorder-Traversal/Binary-Tree-Preorder-Traversal.py)
###  递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        self.helper(root, res)
        return res
    def helper(self, root, res):
        if root is None:
            return
        res.append(root.val)
        self.helper(root.left, res)
        self.helper(root.right, res)
```

###  迭代
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        self.helper(root, res)
        return res
    def helper(self, root, res):
        if root is None:
            return
        res.append(root.val)
        self.helper(root.left, res)
        self.helper(root.right, res)
```
