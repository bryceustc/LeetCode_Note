# 题目描述:  反转链表

反转一个单链表。

**示例 :**
```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```
**进阶:** 
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
  
# 解题思路:
此题与剑指offer第6题从尾到头打印链表类似

有两种方法：

方法一：非递归方法，利用两个结点指针和一个中间结点指针temp(用来记录当前结点的下一个节点的位置)，分别指向当前结点和前一个结点，每次循环让当前结点的指针域指向前一个结点即可，翻转结束后，记得将最后一个节点的链域置为空。

方法二：递归方法，先反转后面的链表，从最后面的两个结点开始反转（递归都是要递归到最深一层），依次向前，将后一个链表结点指向前一个结点，注意每次反转后要将原链表中前一个结点的指针域置空，表示将原链表中前一个结点指向后一个结点的指向关系断开。

 
# 时间复杂度：
  假设 n 是列表的长度，时间复杂度是 O(n)。
# 空间复杂度
  方法一：O(1)
  
  方法二：O(n),由于使用递归，将会使用隐式栈空间。递归深度可能会达到 n 层。
# 代码

## [C++](./Reverse-Linked-List.cpp):

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next==NULL)
            return head;
        ListNode* p = NULL;
        ListNode* cur = head;
        ListNode* temp = head->next;
        while (cur)
        {
            temp = cur->next; // temp作为中间节点，记录当前节点的下一节点位置
            cur->next = p; // 当前节点指向前一个节点
            p = cur;  // 指针后移
            cur = temp; // 指针后移，处理下一节点
        }
        return p;
    }
};
```
### 方法二：递归法
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
    ListNode* reverseList(ListNode* head) {
        // 递归终止条件，找到链表最后一个节点
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        else
        {
            ListNode* newhead = reverseList(head->next);// 先反转后面的链表，从最后面两个节点开始，
            head->next->next = head;  // 将后一个链表节点指向前一个链表节点
            head->next = NULL;  // 将原链表中前一个节点指向后一个节点的指向关系断开
            return newhead;
        }
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Reverse-Linked-List/Reverse-Linked-List.py)
###  方法一：非递归法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head==None or head.next==None:
            return head
        p = None
        cur = head
        temp = head.next
        while cur:
            temp = cur.next
            cur.next = p
            p = cur
            cur = temp
        return p
```

### 方法二：非递归法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        else:
            newhead = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return newhead
```
# 参考
  - [剑指offer第6题-从尾到头打印链表](https://github.com/bryceustc/CodingInterviews/blob/master/PrintListInReversedOrder/README.md)
