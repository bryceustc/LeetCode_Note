# 题目描述:  从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。

**注意:**

你可以假设树中没有重复的元素。

例如，给出
```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```

返回如下的二叉树：
```
    3
   / \
  9  20
    /  \
   15   7
```
  
# 解题思路:
此题与剑指offer第7题重建二叉树类似，
理解二叉树以及三种遍历的概念。

注意前序遍历中的第一个数字是根节点的值，在中序遍历中根节点的值在序列中间，左子树的节点的值在根节点的值的左边，而右子树的节点的值位于根节点的右边，所以先扫描中序遍历，找到根节点所在位置，然后找到左子树和右子树的前序遍历和中序遍历即可。如图所示：

![](https://github.com/bryceustc/CodingInterviews/blob/master/ConstructBinaryTree/Images/1.jpg)
 
# 时间复杂度：
   O(n)
   
   我们用[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)来计算时间复杂度.
   
   ![2](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal/Images/2.jpg)
# 空间复杂度
  O(n)
# 代码

## [C++](./Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal.cpp):

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        int n = preorder.size();
        vector<int> left_pre,right_pre,left_in,right_in;
        // 前序遍历的第一个数字是根节点的值
        int root = preorder[0];
        TreeNode* t = new TreeNode(root);
        // 长度为1 直接返回
        if (n==1) return t;

        //我们先找到root所在的位置，确定好前序和中序中左子树和右子树序列的范围
        int root_index = 0;
        for (int i=0;i<n;i++)
        {
            if (inorder[i] == root)
            {
                root_index = i;
                break;
            }
        }
        // 左子树
        for (int i=0;i<root_index;i++)
        {
            left_in.push_back(inorder[i]);
            left_pre.push_back(preorder[i+1]); // +1 是因为前序第一个为根节点
        } 
        // 右子树
        for (int i=root_index+1;i<n;i++)
        {
            right_pre.push_back(preorder[i]);
            right_in.push_back(inorder[i]);
        }
        //和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        t->left = buildTree(left_pre, left_in);
        t->right = buildTree(right_pre,right_in);
        return t;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal.py)
###  
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        n = len(preorder)
        root = preorder[0]
        t = TreeNode(root)
        root_index = 0
        for i in range(n):
            if inorder[i]==root:
                root_index = i
                break
        left_pre = []
        left_in = []
        right_pre = []
        right_in = []
        for i in range (root_index):
            left_pre.append(preorder[i+1])
            left_in.append(inorder[i])
        for i in range(root_index+1,n):
            right_pre.append(preorder[i])
            right_in.append(inorder[i])
        t.left = self.buildTree(left_pre,left_in)
        t.right = self.buildTree(right_pre, right_in)
        return t
```
### 简洁版
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        root = TreeNode(preorder.pop(0))
        index = inorder.index(root.val)
        root.left = self.buildTree(preorder, inorder[:index])
        root.right = self.buildTree(preorder, inorder[index+1:])
        return root
```
# 参考
  - [剑指offer第7题-重建二叉树](https://github.com/bryceustc/CodingInterviews/blob/master/ConstructBinaryTree/README.md)
  - [LeetCode-106题-从中序与后序遍历序列构造二叉树](  - [LeetCode-106题-从中序与后序遍历序列构造二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Construct-Binary-Tree-From-Ineorder-And-Postorder-Traversal/README.md)
