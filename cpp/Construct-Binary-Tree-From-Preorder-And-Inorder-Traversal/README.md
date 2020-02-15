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

###  方法一：非递归法
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p && p->next)
        {
            ListNode* temp = p->next;
            if (temp && p->val == temp->val)
            {
                ListNode* del = p->next;
                p->next = temp->next;
                delete del;//C++这类没有垃圾回收的语言别忘了释放删除节点的内存
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};
```
### 方法二：递归方法：
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next==NULL)
            return head;
        head->next = deleteDuplicates(head->next);
        if (head->val == head->next->val) 
            head = head->next;
        return head;        
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal/Construct-Binary-Tree-From-Preorder-And-Inorder-Traversal.py)
###  方法一：非递归法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head==None or head.next == None:
            return head
        p = head
        while p and p.next:
            temp = p.next
            if temp and p.val==temp.val:
                p.next = temp.next
            else:
                p = p.next
        return head
```
### 方法二：递归法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head==None or head.next==None:
            return head
        head.next = self.deleteDuplicates(head.next)
        if head.val==head.next.val:
            head = head.next
        return head
```
# 参考
  - [剑指offer第7题-重建二叉树](https://github.com/bryceustc/CodingInterviews/blob/master/ConstructBinaryTree/README.md)
  - [LeetCode-106题-从中序与后序遍历序列构造二叉树](  - [LeetCode-106题-从中序与后序遍历序列构造二叉树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Construct-Binary-Tree-From-Ineorder-And-Postorder-Traversal/README.md)
