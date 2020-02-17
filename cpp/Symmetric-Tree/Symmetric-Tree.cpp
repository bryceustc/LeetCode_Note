// Solution 1:
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        if (root!=NULL)
        {
            res = helper(root->left,root->right);
        }
        return res;
    }

    bool helper(TreeNode*A, TreeNode* B)
    {
        // 先写递归终止条件
        if (A==NULL && B==NULL)
            return true;
        // 如果其中之一为空，也不是对称的
        if (A==NULL || B==NULL)
            return false;
        // 走到这里二者一定不为空
        if (A->val != B->val)
            return false;
        // 前序遍历
        return helper(A->left,B->right) && helper(A->right,B->left);
    }
};
// Solution 2:
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root ==NULL)
            return true;
        //用队列保存节点
        queue<TreeNode*> q;
        //将根节点的左右孩子放到队列中
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            //从队列中取出两个节点，再比较这两个节点
            TreeNode* A = q.front();
            q.pop();
            TreeNode* B = q.front();
            q.pop();
            //如果两个节点都为空就继续循环，两者有一个为空就返回false
            if (A==NULL && B==NULL)
                continue;
            if (A==NULL || B==NULL)
                return false;
            if (A->val != B->val)
                return false;
            //将左子树的左孩子， 右子树的右孩子放入队列
            q.push(A->left);
            q.push(B->right);
            //将左子树的右孩子，右子树的左孩子放入队列
            q.push(A->right);
            q.push(B->left);
        }
        return true;
    }
};
