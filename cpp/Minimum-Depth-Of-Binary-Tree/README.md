# 题目描述:  二叉树的最小深度

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

**示例：**
给定二叉树 [3,9,20,null,null,15,7],
```
    3
   / \
  9  20
    /  \
   15   7
```
返回它的最小深度  2.

# 解题思路:
dfs与bfs

# 时间复杂度：
  O(n)  其中 n 是树的节点数。对每个节点访问一次。
# 空间复杂度
  O(h) 其中 h 是树的高度。空间复杂度主要取决于递归时栈空间的开销，最坏情况下，树呈现链状，空间复杂度为 O(n)。平均情况下树的高度与节点数的对数正相关，空间复杂度为 O(logN)。

# 代码

###  dfs
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        //1.左孩子和有孩子都为空的情况，说明到达了叶子节点，直接返回1
        if (root->left == NULL && root->right == NULL) return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        //2.如果左孩子和右孩子其中一个为空，说明left和right有一个必然为0，所以可以返回left + right + 1;
        if (root->left == NULL || root->right == NULL) {
            return left + right + 1;
        }
        //3.最后一种情况，也就是左右孩子都不为空，返回左右子树的最小深度+1即可
        return min(left, right) + 1;
    }
};
```
### bfs
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (q.size() > 0) {
            auto node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (node->left == NULL && node->right == NULL) {
                return depth;
            }
            if (node->left != NULL) {
                q.push({node->left, depth + 1});
            }
            if (node->right != NULL) {
                q.push({node->right, depth + 1});
            }
        }
        return 0;
    }
};
```
