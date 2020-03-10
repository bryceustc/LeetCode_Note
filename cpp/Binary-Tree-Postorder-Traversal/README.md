# 题目描述:  二叉树的后序遍历

给定一个二叉树，返回它的 *后序* 遍历。

**示例：**
```
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
```

# 解题思路:
递归与迭代两种方法

方法一：递归

  后序遍历：左子树 ---> 右子树 ---> 根结点，比较容易利用递归写出

方法二：迭代
   
   使用栈（先进后出）来完成,我们先将根节点放入栈中,从根节点开始，每次迭代弹出当前栈顶元素，并将其孩子节点压入栈中，先压左子树再压右子树，然后在调用reverse函数。
   
   使用一个指针lastVisited记录最后访问的节点，一个根节点被访问的前提是：无右子树或右子树已被访问过。

# 时间复杂度：
  O(n) 
# 空间复杂度
  O(n)
# 代码

## [C++](./Binary-Tree-Postorder-Traversal.cpp):

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
    vector<int> postorderTraversal(TreeNode* root) {
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
        helper(root->right,res);
        res.push_back(root->val);
    }
};
```

###  迭代(栈实现，然后调用reverse函数)
```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            if (node->left)
                s.push(node->left);
            if (node->right)
                s.push(node->right);
            res.push_back(node->val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```
### 迭代
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* lastVisited = NULL;
        while(!s.empty() || p)
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            if (p->right == NULL || p->right == lastVisited)
            {
                res.push_back(p->val);
                s.pop();
                lastVisited = p;
                p = NULL; // p 已经访问过了，没用了设置为NULL
            }
            else
            {
                p = p->right;
            }
        }
        return res;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Binary-Tree-Postorder-Traversal/Binary-Tree-Postorder-Traversal.py)
###  递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res
        self.helper(root,res)
        return res
    def helper(self,root,res):
        if root is None:
            return
        self.helper(root.left,res)
        self.helper(root.right,res)
        res.append(root.val)
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
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        s = []
        s.append(root)
        while s:
            node = s.pop()
            if node.left:
                s.append(node.left)
            if node.right:
                s.append(node.right)
            res.append(node.val)
        return res[::-1]
```

