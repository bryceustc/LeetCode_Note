# 题目描述: 二叉树的所有路径

给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

**示例 :**
```
输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
```
  
# 解题思路:

  前序遍历即可

# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(1)
  
# 代码

### 方法一： 注意out不要加引用，右值引用
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        string out = "";
        dfs(root, out, path);
        return path;
    }
    void dfs(TreeNode* root, string out, vector<string> &path)
    {
        if (root==NULL) return;
        out+=to_string(root->val);
        if (root->left==NULL && root->right==NULL) // 叶子节点
        {
            path.push_back(out);
            return;
        }
        dfs(root->left,out + "->",path);
        dfs(root->right,out + "->",path);
    }
};
```
