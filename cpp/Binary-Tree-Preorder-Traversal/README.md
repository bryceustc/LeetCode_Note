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

   前序遍历：根结点 ---> 左子树 ---> 右子树，比较容易利用递归写出

方法二：迭代
   
   使用栈（先进后出）来完成,我们先将根节点放入栈中,从根节点开始，每次迭代弹出当前栈顶元素，并将其孩子节点压入栈中，先压右孩子再压左孩子。

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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!q.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            if (node->right)
            {
                s.push(node->right);
            }
            if (node->left)
            {
                s.push(node->left);
            }
            
        }
        return res;
    }
};
```
### 迭代
```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty() || p!=NULL)
        {
            while(p!=NULL)
            {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            p = s.top();
            s.pop();
            p = p->right;
        }
        return res;
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
        s = []
        s.append(root)
        ## s = [root,] 
        #,理解 这个是方便多行定义的时候复制的,否则容易在添加元素的过程中缺少逗号出现语法错误.
        # 具体可以查python data structure trailing comma这个关键词. 
        # 对于tuple的定义就有差别了,因为(1)这个东西有二意性,所以tuple声明单元素的时候必须加逗号,也就是(1,)
        while s:
            node = s.pop()
            res.append(node.val)
            if node.right:
                s.append(node.right)
            if node.left:
                s.append(node.left)
        return res
```
### 迭代
```python
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res
        s = []
        p = root
        while s or p:
            while p:
                s.append(p)
                res.append(p.val)
                p=p.left
            p = s.pop()
            p = p.right
        return res
```
