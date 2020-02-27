# 题目描述: 二叉树的最大深度

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明: **  

叶子节点是指没有子节点的节点。

**示例：**

给定二叉树: [3,9,20,null,null,15,7],

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。

# 解题思路:
此题与剑指offer第55题的二叉树的深度一样
 
推荐用递归，取左右子树最大的深度加上1

两种方法：可以是递归的方法，属于DFS（深度优先搜索）；另一种方法是按照层次遍历，属于BFS（广度优先搜索）。

# 时间复杂度：
  O(n) 
# 空间复杂度
  O(n)
# 代码

## [C++](./Maximum-Depth-Of-Binary-Tree.cpp):

###  DFS  递归
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};
```

###  BFS  层次遍历 迭代
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL)
            return depth;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count = q.size();
            while (count>0)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                count--;
            }
            depth++;
        }
        return depth;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Maximum-Depth-Of-Binary-Tree/Maximum-Depth-Of-Binary-Tree.py)
###  DFS 递归
```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        return max(left, right)+1
```

### BFS  层次遍历 迭代
```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        depth = 0
        if root is None:
            return depth
        q = []
        q.append(root)
        while q:
            count = len(q)
            while count >0:
                node = q.pop(0)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                count -=1
            depth+=1
        return depth
```

# 参考
  - [剑指offer第55题-之字形打印二叉树](https://github.com/bryceustc/CodingInterviews/blob/master/TreeDepth/README.md)
  - [利用STL中的队列queue对二叉树进行层遍历](https://blog.csdn.net/iamxiaoguizi/article/details/51220678) 
