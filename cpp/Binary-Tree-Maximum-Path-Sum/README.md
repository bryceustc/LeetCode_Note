# 题目描述:  二叉树中的最大路径和

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。 

**示例 1 :**
```
输入: [1,2,3]

       1
      / \
     2   3

输出: 6
```
**示例 2 :**
```
输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
```
# 解题思路:
树的题一般用递归来做，递归考虑左子树的最大值，递归考虑右子树的最大值。
# 时间复杂度：
  O(n)
  
# 空间复杂度
O(n)
  
# 代码

###  方法一： 递归法
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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        dfs(root);
        return res;
    }
    //后序遍历树，返回经过root的单边最大路径和，并维护整棵树的最大路径和
    int dfs(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        //计算左边分支最大值，左边分支如果为负数还不如不选择
        int left = max(0,dfs(root->left));
        //计算右边分支最大值，右边分支如果为负数还不如不选择
        int right = max(0,dfs(root->right));
        //由于路径最大的一种可能为left->node->right，而不向root的父结点延伸
        res = max(res,root->val + left + right);
        // 向的父结点返回经过root的单边分支的最大路径和
        return root->val + max(left, right);
    }
    
};
```
