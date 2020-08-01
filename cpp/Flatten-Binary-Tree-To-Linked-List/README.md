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
        
        flatten(root -> left);
        flatten(root -> right);
        if (root -> left) {
            TreeNode* cur = root -> left;
            while (cur -> right) {
                cur = cur -> right;
            }
            cur -> right = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
        }
        return ;
    }
};
```
