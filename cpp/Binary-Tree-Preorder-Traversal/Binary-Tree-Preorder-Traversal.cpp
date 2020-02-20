// Solution 1:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
    }
};
// Solution 2:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!q.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            if (node->right)
            {
                s.push(node->right);
            }
            if (node->left)
            {
                s.push(node->left);
            }
            
        }
        return res;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty() || p!=NULL)
        {
            while(p!=NULL)
            {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            p = s.top();
            s.pop();
            p = p->right;
        }
        return res;
    }
};
