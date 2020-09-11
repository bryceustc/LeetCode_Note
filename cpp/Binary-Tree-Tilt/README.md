# 题目: 二叉树的坡度

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

整个树的坡度就是其所有节点的坡度之和。

## 题目描述：
给定一个二叉树，计算整个树的坡度。
  
  **示例：**
  给定二叉树
  ```
输入：
         1
       /   \
      2     3
输出：1
解释：
结点 2 的坡度: 0
结点 3 的坡度: 0
结点 1 的坡度: |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1
  ```
  
# 解题思路:

  此题与二叉树的直径类似，需要灵活运用dfs

# 时间复杂度：
O(n)
# 空间复杂度
 O(n)
# 代码

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
    int findTilt(TreeNode* root) {
        if (root == NULL) return 0;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int left =dfs(root->left);
        int right = dfs(root->right);
        res += abs(left - right);
        return root->val + left + right; // 坡度的定义，左右子树节点的和
    }
private:
    int res = 0;
};
```
