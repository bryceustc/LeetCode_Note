# 题目描述:  相同的树

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

**示例 :**
```
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
```
# 解题思路:
  递归判断
# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(n)
  
# 代码

###  
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL) return true;
        if (p==NULL && q!=NULL) return false;
        if (p!=NULL && q==NULL) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};
```
