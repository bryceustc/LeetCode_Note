# 题目描述:  另一个树的子树

给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。


**示例 :**
给定的树 s:
```
     3
    / \
   4   5
  / \
 1   2
给定的树 t：
    4 
  / \
 1   2
```
# 解题思路:
判断镜像二叉树类似
# 时间复杂度：
  方法一： O(n+m)
  
  方法二： O(n+m)
  
# 空间复杂度
  方法一：O(1)
  
  方法二：O(n+m)
  
# 代码

###  
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s==nullptr&&t==nullptr) return true;
        if (s==nullptr&&t!=nullptr) return false;
        return isSametree(s,t) || isSubtree(s->left,t)||isSubtree(s->right,t);
    }
    bool isSametree(TreeNode*s, TreeNode* t)
    {
        if(s==nullptr && t==nullptr) return true;
        return s&&t && s->val==t->val && isSametree(s->left, t->left) && isSametree(s->right,t->right);
    }
};
```
