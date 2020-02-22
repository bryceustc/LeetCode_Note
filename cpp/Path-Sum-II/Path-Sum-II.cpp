class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> path;
        dfs(root, res, path, sum);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>> &res, vector<int> &path, int sum)
    {
        if (root == NULL)
            return;
        path.push_back(root->val);
        bool isLeaf = (root->left == NULL) && (root->right == NULL);
        if (sum == root->val && isLeaf)
        {
            res.push_back(path);
        }
        dfs(root->left, res, path, sum - root->val);
        dfs(root->right, res, path,sum - root->val);
        path.pop_back();
    }
};
