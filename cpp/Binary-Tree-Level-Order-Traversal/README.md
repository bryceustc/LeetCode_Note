# 题目描述:  二叉树的层次遍历

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

```
    3
   / \
  9  20
    /  \
   15   7
```

返回其层次遍历结果：
```
[
  [3],
  [9,20],
  [15,7]
]
```

  
# 解题思路:
此题与剑指offer第32题分行从上到下打印二叉树

  方法一：递归
  
   - 找出终止条件

   - 找出返回值

   -明确这一步递归干了什么
   
  方法二：迭代
  
  利用STL中的容器队列来实现，注意计算出当前层有多少个元素：等于队列的长度，按照顺序遍历完队列加入out中。

第 0 层只包含根节点 root，算法实现如下：

  -  初始化队列只包含一个节点 root。
  - 当队列非空的时候：
      - 计算当前层有多少个元素：等于队列的长度。
      - 初始化一个空列表out
      - 利用循环将这些元素从队列中弹出，并加入out空列表中。
      - 将他们的孩子节点作为下一层压入队列中。
      - 将out列表加入res中，进入下一层。
 
# 时间复杂度：
  方法一：O(n) 
  
  方法二：O(n)

# 空间复杂度
  方法一：O(n)

  方法二：O(n)
# 代码

## [C++](./Binary-Tree-Level-Order-Traversal.cpp):

###  方法一： 递归
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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};
```

###  方法二： 迭代 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            vector<int> out;
            while (count >0)
            {
                TreeNode* node = q.front();
                q.pop();
                out.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                count--;
            }
            res.push_back(out);
        }
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Binary-Tree-Level-Order-Traversal/Binary-Tree-Level-Order-Traversal.py)
###  方法一：递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return root
        temp = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(temp)
        return root
```
### 方法二 ： 迭代
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = []
        q.append(root)
        while q:
            n = len(q)
            out = []
            while n>0:
                node = q.pop(0)
                out.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                n-=1
            res.append(out[:])
        return res
```

# 参考
  - [剑指offer第32题-分行从上到下打印二叉树(https://github.com/bryceustc/CodingInterviews/blob/master/PrintTreeFromTopToBottom/README.md)
  - [利用STL中的队列queue对二叉树进行层遍历](https://blog.csdn.net/iamxiaoguizi/article/details/51220678) 
