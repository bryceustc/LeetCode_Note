# 题目描述:  二叉树的中序遍历

给定一个二叉树，返回它的 *中序* 遍历。

**示例：**
```
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
```
d
# 解题思路:
递归与迭代两种方法

方法一：递归

  中序遍历：左子树---> 根结点 ---> 右子树，比较容易利用递归写出

方法二：迭代
   
   根据中序遍历的顺序，优先访问左子树，然后在访问根节点和右子树。所以，对于任意结点node，第一部分即直接访问之，之后在判断左子树是否为空，不为空时即重复上面的步骤，直到其为空。若为空，则需要访问右子树。注意，在访问过左孩子之后，需要反过来访问其右孩子，所以，需要栈这种数据结构的支持。对于任意一个结点node，具体步骤如下：

a)访问之，并把结点node入栈，当前结点置为左孩子；

b)判断结点node是否为空，若为空，则取出栈顶结点并出栈，将右孩子置为当前结点；否则重复a)步直到当前结点为空或者栈为空（可以发现栈中的结点就是为了访问右孩子才存储的）
   

# 时间复杂度：
  O(n) 
# 空间复杂度
  递归：最坏情况下需要空间O(n)，平均情况为O(logn)。
# 代码

## [C++](./Binary-Tree-Inorder-Traversal.cpp):

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
    vector<int> inorderTraversal(TreeNode* root) {
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
        helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);
    }
};
```

###  迭代
```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>  res;
        if (root==NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty()||p!=NULL)
        {
            while(p!=NULL)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Binary-Tree-Inorder-Traversal/Binary-Tree-Inorder-Traversal.py)
###  递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res
        self.helper(root,res)
        return res
    def helper(self,root,res):
        if root is None:
            return
        self.helper(root.left,res)
        res.append(root.val)
        self.helper(root.right,res)
```

###  迭代 
```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        s = []
        p = root
        while p or s:
            while p!=None:
                s.append(p)
                p = p.left
            p = s.pop()
            res.append(p.val)
            p = p.right
        return res
```


