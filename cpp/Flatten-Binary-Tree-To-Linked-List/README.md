```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return ;
        //将根节点的左子树变成链表
        flatten(root -> left);
        //将根节点的右子树变成链表
        flatten(root -> right);
        
        TreeNode* temp = root->right;
        //把树的右边换成左边的链表
        root->right = root->left;
        //记得要将左边置空
        root->left = NULL;
        //找到树的最右边的节点
        while (root->right != NULL) root = root->right;
        //把右边的链表接到刚才树的最右边的节点
        root->right =temp;
        return ;
    }
};
```
