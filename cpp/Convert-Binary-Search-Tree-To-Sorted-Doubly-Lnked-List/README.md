# 题目描述: 将二叉搜索树转换成排序的双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

以下面的二叉搜索树为例：

![](https://assets.leetcode.com/uploads/2018/10/12/bstdlloriginalbst.png)

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

![](https://assets.leetcode.com/uploads/2018/10/12/bstdllreturndll.png)

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
  
# 解题思路:

 举例说明：
  
  ![](https://cuijiahua.com/wp-content/uploads/2017/12/basis_26_1.jpg)
  
  二叉搜索树如上图所示，我们将其转换为配需双向链表。

根据二叉搜索树的特点：左结点的值<根结点的值<右结点的值，我们不难发现，使用二叉树的中序遍历出来的数据的数序，就是排序的顺序。因此，首先，确定了二叉搜索树的遍历方法。

接下来，我们看下图，我们可以把树分成三个部分：值为10的结点、根结点为6的左子树、根结点为14的右子树。根据排序双向链表的定义，值为10的结点将和它的左子树的最大一个结点链接起来，同时它还将和右子树最小的结点链接起来。
  
  ![](https://cuijiahua.com/wp-content/uploads/2017/12/basis_26_3.jpg)
  
  按照中序遍历的顺序，当我们遍历到根结点时，它的左子树已经转换成一个排序的好的双向链表了，并且处在链表中最后一个的结点是当前值最大的结点。我们把值为8的结点和根结点链接起来，10就成了最后一个结点，接着我们就去遍历右子树，并把根结点和右子树中最小的结点链接起来。
# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Convert-Binary-Search-Tree-To-Sorted-Doubly-Lnked-List.cpp):

###  中序遍历
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root==NULL)
            return NULL;
        Node* pre = NULL;
        helper(root, pre);
        Node* head =pre;
        while(head && head->left)
        {
            head = head->left;
        }
        pre -> right = head;
        head->left = pre;
        return head;
    }
    void helper(Node* cur, Node* &pre)
    {
        if (cur==NULL)
            return;
        helper(cur->left, pre);
        cur->left = pre;
        if (pre!=NULL)
            pre->right = cur;
        pre = cur;
        helper(cur->right, pre);
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Add-Strings/Add-Strings.py)
### 中序遍历
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if root  is None:
            return None
        pre = None
        pre = self.helper(root, pre)
        head = pre
        while head and head.left:
            head = head.left
        pre.right = head
        head.left = pre
        return head
    def helper(self, cur,  pre):
        if cur == None:
            return pre
        pre = self.helper(cur.left, pre)
        cur.left = pre
        if pre:
            pre.right = cur
        pre = cur
        return self.helper(cur.right, pre)
```
# 参考
  - [剑指offer-36题-二叉搜索树与双向链表](https://github.com/bryceustc/CodingInterviews/blob/master/ConvertBinarySearchTree/README.md)
