# 题目描述:  删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

**示例 :**
```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```
**说明:**
  给定的 n 保证是有效的。(排除了一些情况)
  
# 解题思路:
此题与剑指offer第22题链表中倒数第k个节点类似，剑指offer那题未保证输入k有效所以要复杂一点。

思路一：直接法，两次遍历

  1.第一次遍历求出链表长度。
  
  2.第二次遍历删掉指定结点。
  
  3.注意删除头结点的特殊情况。

思路二：双指针，一次遍历。

  我们可以设想假设设定了双指针p和q的话，当q指向末尾的NULL，p与q之间相隔的元素个数为n时，那么删除掉p的下一个指针就完成了要求。
  
  1.设置虚拟节点dummyHead指向head。
  
  2.移动q，直到p与q之间相隔的元素个数为n。
  
  3.同时移动p与q，直到q指向的为NULL，将p的下一个节点指向下下个节点。
 
# 时间复杂度：
   O(n)。
# 空间复杂度
  O(1)
# 代码

## [C++](./Remove-Nth-Node-From-End-Of-List.cpp):

###  方法一：直接法
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        int len = 0;
        for (ListNode* temp = head;temp!=NULL;temp=temp->next)
        {
            len++;
        }
        if (len==n) return head->next;
        int i = 0;
        for (ListNode* temp = head;temp!=NULL;temp=temp->next)
        {
            i++;
            if (i==len-n)
            {
                temp->next = temp->next->next;
                break;
            }
        }
        return head;
    }
};
```
###  方法二：双指针法
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* p = dummyhead;
        ListNode* q = dummyhead;
        // 因为指向dummyhead，所以需要移动n步，而不是n-1步
        for (int i=0;i<n;i++)
        {
            q = q->next;
        }
        while (q->next!=NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Remove-Nth-Node-From-End-Of-List/Remove-Nth-Node-From-End-Of-List.py)
###  
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head == None:
            return None
        l = 0
        temp = head
        while temp:
            l+=1
            temp = temp.next
        if l==n:
            return head.next
        i = 0
        p = head
        while p:
            i+=1
            if i == l-n:
                p.next = p.next.next
                break
            else:
                p = p.next
        return head
```
### 方法二：双指针（一次遍历）
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head == None:
            return None
        dummyhead = ListNode(-1)
        dummyhead.next = head
        p = dummyhead
        q = dummyhead
        for i in range(n):
            q = q.next
        while q.next!=None:
            p = p.next
            q = q.next
        p.next = p.next.next
        return dummyhead.next
```
# 参考
  - [剑指offer第22题-链表中倒数第k个节点](https://github.com/bryceustc/CodingInterviews/blob/master/KthNodeFromEnd/README.md)

