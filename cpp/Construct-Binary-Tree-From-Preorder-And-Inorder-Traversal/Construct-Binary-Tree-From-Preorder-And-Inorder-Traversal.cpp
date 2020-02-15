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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        int n = preorder.size();
        vector<int> left_pre,right_pre,left_in,right_in;
        // 前序遍历的第一个数字是根节点的值
        int root = preorder[0];
        TreeNode* t = new TreeNode(root);
        // 长度为1 直接返回
        if (n==1) return t;

        //我们先找到root所在的位置，确定好前序和中序中左子树和右子树序列的范围
        int root_index = 0;
        for (int i=0;i<n;i++)
        {
            if (inorder[i] == root)
            {
                root_index = i;
                break;
            }
        }
        // 左子树
        for (int i=0;i<root_index;i++)
        {
            left_in.push_back(inorder[i]);
            left_pre.push_back(preorder[i+1]); // +1 是因为前序第一个为根节点
        } 
        // 右子树
        for (int i=root_index+1;i<n;i++)
        {
            right_pre.push_back(preorder[i]);
            right_in.push_back(inorder[i]);
        }
        //和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        t->left = buildTree(left_pre, left_in);
        t->right = buildTree(right_pre,right_in);
        return t;
    }
};
