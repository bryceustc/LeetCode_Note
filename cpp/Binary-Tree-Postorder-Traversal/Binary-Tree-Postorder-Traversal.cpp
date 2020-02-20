class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root, vector<int> &res)
    {
        if (root==NULL)
            return;
        helper(root->left,res);
        helper(root->right,res);
        res.push_back(root->val);
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            if (node->left)
                s.push(node->left);
            if (node->right)
                s.push(node->right);
            res.push_back(node->val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
