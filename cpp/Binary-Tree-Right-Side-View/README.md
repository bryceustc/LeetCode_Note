# 题目描述:  二叉树的右视图

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

**示例 :**
```
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```

# 解题思路:
1. BFS

- 按层来遍历，先遍历每一层的右子树

2. DFS

- 按照根节点-右子树-左子树来遍历，逆前序遍历

# 时间复杂度：
 1. O(n)
 
 2. O(n)
# 空间复杂度
 1. O(n)
 
 2. O(n)
# 代码

### BFS
```c++
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            res.push_back(q.front()->val);
            while(n>0)
            {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->right) q.push(temp->right);
                if (temp->left) q.push(temp->left);
                n--;
            }
        }
        return res;
    }
};
```
### DFS
```c++
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root,0,res);
        return res;
    }
    void dfs(TreeNode* root, int depth, vector<int> &res)
    {
        if (root==NULL) return;
        if (depth==res.size()) // 利用结果res的size等于tree的高度的性质
        {
            res.push_back(root->val);
        }
        dfs(root->right,depth+1, res);
        dfs(root->left, depth+1, res);
    }
};
```
