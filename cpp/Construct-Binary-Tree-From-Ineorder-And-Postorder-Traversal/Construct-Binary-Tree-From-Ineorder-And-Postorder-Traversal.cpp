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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;
        int n = inorder.size();
        int root = postorder[n-1];
        TreeNode* t = new TreeNode(root);
        if (n==1) return t;
        vector<int> left_in, left_post, right_in, right_post;
        int root_index = 0;
        for (int i=0;i<n;i++)
        {
            if (inorder[i] == root)
            {
                root_index=i;
                break;
            }
        }
        for (int i=0;i<root_index;i++)
        {
            left_in.push_back(inorder[i]);
            left_post.push_back(postorder[i]);
        }
        for (int i=root_index+1;i<n;i++)  // +1是跳过根节点
        {
            right_in.push_back(inorder[i]);
        }
        for (int i =root_index;i<n-1;i++)  // -1是跳过根节点
        {
            right_post.push_back(postorder[i]);
        }
        t->left = buildTree(left_in, left_post);
        t->right = buildTree(right_in, right_post);
        return t;
    }
};
