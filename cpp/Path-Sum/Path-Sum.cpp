class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        if (root == NULL)
            return res;
         helper(root, sum, res);
        return res;
    }
    void helper(TreeNode* root, int expectNumber, bool &res)
    {
        if (root == NULL)
            return;
        bool isLeaf = root->left == NULL && root->right == NULL;
        if (expectNumber == root->val && isLeaf)
        {
            res = true;
        }
        helper(root->left, expectNumber-root->val, res);
        helper(root->right, expectNumber-root->val, res);
    }
};


// Solution 2:
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL)
            return false;
        sum -= root->val;
        bool isLeaf = (root->left==NULL) && (root->right==NULL);
        if (isLeaf)
        {
            return sum==0;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
