# 题目描述:  平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

```
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
```

**示例1:**

给定二叉树 [3,9,20,null,null,15,7]
```
    3
   / \
  9  20
    /  \
   15   7
```
返回 true 。

**示例2:**

给定二叉树 [1,2,2,3,3,null,null,4,4]
```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```
返回 false。
  
# 解题思路:
此题与剑指offer第55题平衡二叉树类似，
 
  解题思路有两种，只遍历一次的方法最优。

**重复遍历多次：自顶向下** 

自顶向下在遍历树的每个结点的时候，调用函数TreeDepth得到它的左右子树的深度。如果每个结点的左右子树的深度相差都不超过1，则这是一颗平衡的二叉树。这种方法的缺点是，首先判断根结点是不是平衡的，需要使用TreeDepth获得左右子树的深度，然后还需要继续判断子树是不是平衡的，还是需要使用TreeDepth获得子树的左右子树的深度，这样就导致了大量的重复遍历。

**只遍历一次：自底向上**

自底向上与自顶向下的逻辑相反，首先判断子树是否平衡，然后比较子树高度判断父节点是否平衡。检查子树是否平衡。如果平衡，则使用它们的高度判断父节点是否平衡，并计算父节点的高度。自底向上计算，每个子树的高度只会计算一次。可以递归先计算当前节点的子节点高度，然后再通过子节点高度判断当前节点是否平衡，从而消除冗余。
# 时间复杂度：
   方法一：O(nlogn) [复杂度分析](https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode/)
  
   方法二：O(n) [复杂度分析](https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode/)
# 空间复杂度
  O(n) [复杂度分析](https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode/)
# 代码

## [C++](./Balanced-Binary-Tree.cpp):

###  重复遍历多次
```c++
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        if (left - right >1 || left -right < -1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int TreeDepth(TreeNode* root)
    {
        if (root==NULL)
            return 0;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        return max(left, right) +1;
    }
};
```
###  只遍历一次
```c++
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int depth = 0;
        return helper(root, depth);
    }
    bool helper(TreeNode* root, int & depth)
    {
        if (root==NULL)
        {
            depth = 0;
            return true;
        }
        int left,right;
        if (helper(root->left, left) && helper(root->right, right) && abs(left-right) <=1)
        {
            depth = max(left, right) +1;
            return true;
        }
        return false;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Balanced-Binary-Tree/Balanced-Binary-Tree.py)
###  重复遍历多次
```python
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        if abs(left-right)>1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
    def TreeDepth(self, root):
        if root is None:
            return 0
        left = self.TreeDepth(root.left)
        right = self.TreeDepth(root.right)
        return max(left, right) + 1
```
### 只遍历一次
```python
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.helper(root)[0]
    def helper(self, root):
        if root is None:
            return True, 0
        leftIsBalanced, left = self.helper(root.left)
        if not leftIsBalanced:
            return False, 0
        rightIsBalanced,right = self.helper(root.right)
        if not rightIsBalanced:
            return False, 0
        return (abs(left - right)<=1), max(left, right) +1
```
# 参考
  - [剑指offer第55题-平衡二叉树](https://github.com/bryceustc/CodingInterviews/blob/master/BalancedBinaryTree/README.md)
