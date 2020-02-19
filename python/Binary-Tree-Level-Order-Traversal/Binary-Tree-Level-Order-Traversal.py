## Python Solution 1:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        helper(root, res,0);
        return res;
    }

    void helper(TreeNode* root, vector<vector<int>> &res, int level)
    {
        if (root==NULL)
            return;
        if (res.size()==level)
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        if (root->left)
            helper(root->left,res,level+1);
        if (root->right)
            helper(root->right,res,level+1);
    }
};
## Python Solution 2:
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = []
        q.append(root)
        while q:
            n = len(q)
            out = []
            while n>0:
                node = q.pop(0)
                out.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                n-=1
            res.append(out[:])
        return res
