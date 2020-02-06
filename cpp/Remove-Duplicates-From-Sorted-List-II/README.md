# 题目描述:  删除排序链表中的重复元素II

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中*没有重复出现*的数字。

**示例 1:**
```
输入: 1->2->3->3->4->4->5
输出: 1->2->5
```
**示例 2:**
```
输入: 1->1->1->2->3
输出: 2->3
```
  
# 解题思路:
此题与剑指offer第18题删除链表中的重复节点一样，与LeetCode83题类似，

思路一：非递归法，直接法，
  - 定义一个虚拟头结点，链接上原链表，prev指向虚拟头结点，cur 指向原链表头部
  - 1.当前结点value ！= 当前结点的下一结点value。那么让pre指针来到当前结点，这样就链接了前一结点和当前结点。然后当前结点移至下一结点
  - 2.当前结点value == 当前结点的下一结点value。那么就让 cur 一直往下走直到 当前结点value ！= 当前结点的下一结点value，然后此时是不能动 pre 指针的，要避免后面还有重复的，所以让 pre->next = cur->next。然后当前结点移至下一结点。
  - 循环结束的条件，``cur!=NULL&&cur->next!=NULL;``

思路二：递归法。

  递归套路解决链表问题：

   - 找终止条件：当head指向链表只剩一个元素的时候，return
   - 想想应该返回什么值：应该返回的自然是已经去重的链表的头节点
   - 每一步要做什么：宏观上考虑，如果当前head和head->next相等，相等则需要一直判断并后移``head = head->next;``，此时head指向重复元素的最后一个值，但这个head我们也不能要，就需要重新建立head，所以``head = deleteDuplicates(head->next);``，如果不相等，head->next指向的就是一个去重的链表。然后返回head
 
# 时间复杂度：
   O(n)。
# 空间复杂度
  O(1)
# 代码

## [C++](./Remove-Duplicates-From-Sorted-List-II.cpp):

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
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* prev = p;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                while (cur->next && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                prev->next = cur->next;
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
        }
        return p->next;
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
        if (head == NULL || head->next == NULL)
            return head;
        if (head->val == head->next->val)
        {
            while(head->next && head->val == head->next->val)
            {
                head = head->next;
            }
            head = deleteDuplicates(head->next);
        }
        else
        {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Remove-Duplicates-From-Sorted-List-II/Remove-Duplicates-From-Sorted-List-II.py)
###  方法一：非递归法
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
        p = ListNode(-1)
        p.next = head
        prev = p
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                while cur.next and cur.val == cur.next.val:
                    cur = cur.next
                prev.next = cur.next
            else:
                prev = cur
            cur = cur.next
        return p.next
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
        if head.val == head.next.val:
            while head.next and head.val == head.next.val:
                head = head.next
            head = self.deleteDuplicates(head.next)
        else:
            head.next = self.deleteDuplicates(head.next)
        return head
```
# 参考
  - [剑指offer第18题-删除链表中的节点](https://github.com/bryceustc/CodingInterviews/blob/master/DeleteDuplicatedNode/README.md)
  - [LeetCode-83题-删除排序链表中的重复元素](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Duplicates-From-Sorted-List/README.md)



