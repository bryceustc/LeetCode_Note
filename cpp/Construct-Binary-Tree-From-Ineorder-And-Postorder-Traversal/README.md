# 题目描述:  从中序与后序遍历序列构造二叉树

根据一棵树的中序遍历与后序遍历构造二叉树。

**注意:**

你可以假设树中没有重复的元素。

例如，给出
```
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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

## [C++](./Construct-Binary-Tree-From-Ineorder-And-Postorder-Traversal.cpp):

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;
        int n = inorder.size();
        int root = postorder[n-1];
        TreeNode* t = new TreeNode(root);
        if (n==1) return t;
        vector<int> left_in, left_post, right_in, right_post;
        int root_index = 0;
        for (int i=0;i<n;i++)
        {
            if (inorder[i] == root)
            {
                root_index=i;
                break;
            }
        }
        for (int i=0;i<root_index;i++)
        {
            left_in.push_back(inorder[i]);
            left_post.push_back(postorder[i]);
        }
        for (int i=root_index+1;i<n;i++)  // +1是跳过根节点
        {
            right_in.push_back(inorder[i]);
        }
        for (int i =root_index;i<n-1;i++)  // -1是跳过根节点
        {
            right_post.push_back(postorder[i]);
        }
        t->left = buildTree(left_in, left_post);
        t->right = buildTree(right_in, right_post);
        return t;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Construct-Binary-Tree-From-Ineorder-And-Postorder-Traversal/Construct-Binary-Tree-From-Ineorder-And-Postorder-Traversal.py)
###  
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return None
        n = len(inorder)
        root = postorder[-1]
        t = TreeNode(root)
        for i in range(n):
            if inorder[i]==root:
                root_index = i
                break
        left_in = []
        left_post = []
        right_in = []
        right_post = []
        for i in range(root_index):
            left_in.append(inorder[i])
            left_post.append(postorder[i])
        for i in range(root_index+1,n):
            right_in.append(inorder[i])
        for i in range(root_index,n-1):
            right_post.append(postorder[i])
        t.left = self.buildTree(left_in, left_post)
        t.right = self.buildTree(right_in, right_post)
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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return None
        root = TreeNode(postorder[-1])
        index = inorder.index(root.val)
        root.left = self.buildTree(inorder[:index],postorder[:index])
        root.right = self.buildTree(inorder[index+1:], postorder[index:-1])
        return root
```
# 参考
  - [剑指offer第7题-重建二叉树](https://github.com/bryceustc/CodingInterviews/blob/master/ConstructBinaryTree/README.md)
  - [LeetCode-105题-从前序与中序遍历序列构造二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal/README.md)

