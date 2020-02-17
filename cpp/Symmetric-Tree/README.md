# 题目描述:  对称二叉树

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
```
    1
   / \
  2   2
   \   \
   3    3
```

  
# 解题思路:
此题与剑指offer第28题类似

  方法一：**递归**
  
  用递归分别比较左右子树
  
  递归结束条件：
   - 都为空指针则返回 true
   - 只有一个为空则返回 false
   - 两个指针当前节点值不相等 返回false
   
 递归过程：
   - 判断 A 的右子树与 B 的左子树是否对称
   - 判断 A 的左子树与 B 的右子树是否对称
   
  方法二：迭代
  
  递归实现也就是深度优先遍历的方式，那么对应的就是广度优先遍历。广度优先遍历需要额外的数据结构--队列，来存放临时遍历到的元素。深度优先遍历的特点是一竿子插到底，不行了再退回来继续；而广度优先遍历的特点是层层扫荡。所以，我们需要先将根节点放入到队列中，然后不断的迭代队列中的元素。对当前元素调换其左右子树的位置，然后：

   - 判断其左子树是否为空，不为空就放入队列中
   - 判断其右子树是否为空，不为空就放入队列中
 
# 时间复杂度：
  方法一：O(n) 
  
  方法二：O(n)

# 空间复杂度
  方法一：O(n)

  方法二：O(n)
# 代码

## [C++](./Symmetric-Tree.cpp):

###  方法一： 递归
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
```

###  方法二： 迭代 
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
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Symmetric-Tree/Symmetric-Tree.py)
###  方法一：递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        res = True
        if root:
            res = self.helper(root.left, root.right)
        return res
    
    def helper(self,A,B):
        if A is None and B is None:
            return True
        if A is None or B is None:
            return False
        if A.val != B.val:
            return False
        return self.helper(A.left,B.right) and self.helper(A.right,B.left)
```
### 方法二 ： 迭代
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        q = []
        q.append(root.left)
        q.append(root.right)
        while len(q)!=0:
            A = q.pop(0)
            B = q.pop(0)
            if A == None and B == None:
                continue
            if A == None or B == None:
                return False
            if A.val != B.val:
                return False
            q.append(A.left)
            q.append(B.right)
            q.append(A.right)
            q.append(B.left)
        return True 
```
# 参考
  - [剑指offer第28题-对称的二叉树](https://github.com/bryceustc/CodingInterviews/blob/master/SymmetricalBinaryTree/README.md)
