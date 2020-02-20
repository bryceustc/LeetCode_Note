class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
        res.push_back(root->val);
        helper(root->right,res);
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>  res;
        if (root==NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty()||p!=NULL)
        {
            while(p!=NULL)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};
