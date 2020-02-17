// C++ Solution 1:
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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};
// C++ Solution 2：
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        queue<TreeNode*> q;
        //将二叉树中的节点逐层放入队列中，再迭代处理队列中的元素
        q.push(root);
        while (!q.empty())
        {
            //每次都从队列中拿一个节点，并交换这个节点的左右子树
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            //如果当前节点的左子树不为空，则放入队列等待后续处理
            if (cur->left!=NULL)
                q.push(cur->left);
            //如果当前节点的右子树不为空，则放入队列等待后续处理
            if (cur->right!=NULL)
                q.push(cur->right);
        }
        return root;
    }
};
