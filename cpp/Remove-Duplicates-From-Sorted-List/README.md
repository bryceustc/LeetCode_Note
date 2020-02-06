# 题目描述:  删除排序链表中的重复元素

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

**示例 1:**
```
输入: 1->1->2
输出: 1->2
```
**示例 2:**
```
输入: 1->1->2->3->3
输出: 1->2->3
```
  
# 解题思路:
此题与剑指offer第18题删除链表中的重复节点类似，

思路一：非递归法，由于输入的列表已排序，因此我们可以通过将结点的值与它之后的结点进行比较来确定它是否为重复结点。如果它是重复的，我们更改当前结点的 next 指针，以便它跳过下一个结点并直接指向下一个结点之后的结点。

思路二：递归法。

  递归套路解决链表问题：

   - 找终止条件：当head指向链表只剩一个元素的时候，自然是不可能重复的，因此return
   - 想想应该返回什么值：应该返回的自然是已经去重的链表的头节点
   - 每一步要做什么：宏观上考虑，此时head.next已经指向一个去重的链表了，而根据第二步，我应该返回一个去重的链表的头节点。因此这一步应该做的是判断当前的head和head.next是否相等，如果相等则说明重了，返回head.next，否则返回head
 
# 时间复杂度：
   O(n)。
# 空间复杂度
  O(1)
# 代码

## [C++](./Remove-Duplicates-From-Sorted-List.cpp):

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
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Remove-Duplicates-From-Sorted-List/Remove-Duplicates-From-Sorted-List.py)
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
  - [剑指offer第18题-删除链表中的节点](https://github.com/bryceustc/CodingInterviews/blob/master/PrintListInReversedOrder/README.md)
  - [LeetCode-82题-删除排序链表中的重复元素II](https://github.com/bryceustc/CodingInterviews/blob/master/PrintListInReversedOrder/README.md)


