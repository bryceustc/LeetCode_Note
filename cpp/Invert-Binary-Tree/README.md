# 题目描述:  翻转二叉树

翻转一棵二叉树。

**示例 :**

输入：
```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

输出：
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

  
# 解题思路:
此题与剑指offer第27题类似

  方法一：递归
  
   - 找出终止条件

   - 找出返回值

   -明确这一步递归干了什么
   
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

## [C++](./Invert-Binary-Tree.cpp):

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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return root;
        queue<TreeNode*> q;
        //将二叉树中的节点逐层放入队列中，再迭代处理队列中的元素
        q.push(root);
        while (!q.empty())
        {
            //每次都从队列中拿一个节点，并交换这个节点的左右子树
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            //如果当前节点的左子树不为空，则放入队列等待后续处理
            if (cur->left!=NULL)
                q.push(cur->left);
            //如果当前节点的右子树不为空，则放入队列等待后续处理
            if (cur->right!=NULL)
                q.push(cur->right);
        }
        return root;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Invert-Binary-Tree/Invert-Binary-Tree.py)
###  方法一：递归
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return root
        temp = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(temp)
        return root
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
    def invertTree(self, root: TreeNode) -> TreeNode:
            if not root:
                return root
            # 将二叉树中的节点逐层放入队列中，再迭代处理队列中的元素
            queue = [root]
            while queue:
                # 每次都从队列中拿一个节点，并交换这个节点的左右子树
                tmp = queue.pop(0)
                tmp.left,tmp.right = tmp.right,tmp.left
                # 如果当前节点的左子树不为空，则放入队列等待后续处理
                if tmp.left:
                    queue.append(tmp.left)
                # 如果当前节点的右子树不为空，则放入队列等待后续处理	
                if tmp.right:
                    queue.append(tmp.right)
            # 返回处理完的根节点
            return root
```

# 参考
  - [剑指offer第27题-二叉树的镜像](https://github.com/bryceustc/CodingInterviews/blob/master/SymmetricalBinaryTree/README.md)
  - [利用STL中的队列queue对二叉树进行层遍历](https://blog.csdn.net/iamxiaoguizi/article/details/51220678) 
