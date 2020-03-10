# 题目: 二叉树的直径

## 题目描述：
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
  
  **示例：**
  给定二叉树
  ```
          1
         / \
        2   3
       / \     
      4   5    
  ```
  返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
  
  注意：两结点之间的路径长度是以它们之间边的数目表示。
  
# 解题思路:

  - 二叉树的直径不一定过根节点，因此需要去搜一遍所有子树(例如以root，root.left, root.right...为根节点的树)对应的直径，取最大值。
  - root的直径 = root左子树高度 + root右子树高度
  - root的高度 = max {root左子树高度, root右子树高度} + 1 (公式记住)

# 时间复杂度：
O(n)
# 空间复杂度
 O(n)
# 代码

# C++: 
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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL) return 0;
        dfs(root);
        return res;
    }

    // 函数dfs的作用是：找到以root为根节点的二叉树的最大深度
    int dfs(TreeNode* root)
    {
        if (root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, left+right);
        return max(left, right) + 1;
    }
};
```
# Python:
###  
```python
class Solution:
    def __init__(self):
        self.res = 0
    
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.dfs(root)
        return self.res
    
    def dfs(self, root):
        if root is None:
            return 0
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        self.res = max(left+right, self.res)
        return max(left, right) + 1
```
