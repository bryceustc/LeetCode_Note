# 题目描述:  二叉树的锯齿形层次遍历

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

```
    3
   / \
  9  20
    /  \
   15   7
```

返回锯齿形层次遍历如下：
```
[
  [3],
  [20,9],
  [15,7]
]
```

  
# 解题思路:
此题与剑指offer第32题之字形打印二叉树一样
 
# 时间复杂度：
  O(n) 
# 空间复杂度
  O(n)
# 代码

## [C++](./Binary-Tree-Zigzag-Level-Order-Traversal.cpp):

###  
```c++
class Solution {
public:
    vector<vector<int>> zigzaglevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        bool flag = true; //从左向右打印为true，从右向左打印为false
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> out;
            TreeNode* node;
            while (n>0)
            {
                if (flag) // 前取后放：从左向右打印，所以从前边取，后边放入
                {
                    node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);  // 下一层顺序存放至尾
                    if (node->right)
                        q.push_back(node->right);
                }
                else  //后取前放： 从右向左，从后边取，前边放入
                {
                    node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.push_front(node->right);  // 下一层逆序存放至首
                    if (node->left)
                        q.push_front(node->left);
                }
                out.push_back(node->val);
                n--;
            }
            flag = !flag;
            res.push_back(out);
        }
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Binary-Tree-Zigzag-Level-Order-Traversal/Binary-Tree-Zigzag-Level-Order-Traversal.py)
###  
```python
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = collections.deque()
        q.append(root)
        zigzag = True
        while q:
            n = len(q)
            out = []
            node = None
            while n>0:
                if zigzag:
                    node = q.popleft()
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                else:
                    node = q.pop()
                    if node.right:
                        q.appendleft(node.right)
                    if node.left:
                        q.appendleft(node.left)
                out.append(node.val)
                n-=1
            res.append(out[:])
            zigzag= not zigzag
        return res
```

# 参考
  - [剑指offer第32题-之字形打印二叉树(https://github.com/bryceustc/CodingInterviews/blob/master/PrintTreesInZigzag/README.md)
  - [利用STL中的队列queue对二叉树进行层遍历](https://blog.csdn.net/iamxiaoguizi/article/details/51220678) 
