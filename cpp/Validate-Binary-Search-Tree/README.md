# 题目描述:  验证二叉搜索树

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

- 节点的左子树只包含小于当前节点的数。
- 节点的右子树只包含大于当前节点的数。
- 所有左子树和右子树自身必须也是二叉搜索树。

**示例 :**
```
输入:
    2
   / \
  1   3
输出: true

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
```
# 解题思路:
二叉搜索树的中序遍历为升序，中序遍历搜索树后判断 是否是严格升序
# 时间复杂度：
 O(n)
  
# 空间复杂度
  O(n)
  
# 代码
###  中序遍历
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
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        set<int> test(res.begin(),res.end());
        vector<int> a;
        a.assign(test.begin(),test.end());
        return res==a;
    }
    void helper(TreeNode* root, vector<int>&res)
    {
        if (root==NULL) return;
        helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);
    }
};
```

###  递归法
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
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        if (root==NULL)
            return true;
        // 访问左子树, 如果左子树为false 返回false
        if (!isValidBST(root->left))
            return false;
        // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
        if (pre && root->val <= pre->val)
            return false;
        // 更新前一个节点
        pre = root;
        // 访问右子树
        return isValidBST(root->right);
    }
};
```
