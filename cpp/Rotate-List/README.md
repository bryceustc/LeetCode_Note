# 题目描述:  旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

**示例 1:**
```
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
```

**示例 2:**
```
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```

  
# 解题思路:
思路一：思路与左旋转字符串类似，利用画图理解，并定义一个向右移动一位的函数rightMove，注意空指针的情形，然后注意k可能大于链表长度，所以这时候需要取一下余，不然会超时

思路二：不需要定义向右移动一位的函数，说是循环旋转，但其实本质上是将尾部向前数第K个元素作为头，原来的头接到原来的尾上。理解这句话：
  - 先将链表闭合成环
  - 找到相应的位置断开这个环，确定新的链表头和链表尾
  
  ![](https://pic.leetcode-cn.com/e3371c6b03e3c8d3758dcf0b35a45d0a6b39c111373cf7b5bde53e14b6271a04-61.png)
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Rotate-List.cpp):

###  方法一： 直接法
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k<=0)
            return head;
        ListNode* temp = head;
        int n = 0;//链表长度
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        ListNode* dummyhead = new ListNode(-1);
        temp = head;
        k = k%n;
        for (int i=0;i<k;i++)
        {
            temp = rightMove(temp);
        }
        dummyhead->next = temp;
        return dummyhead->next;
    }
    ListNode* rightMove(ListNode* head)
    {
        if (head==NULL || head->next==NULL) 
            return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp = head;
        while(cur->next!=NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        cur->next = temp;
        return cur;
    }
};
```

###  方法一改进版：
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k<=0)
            return head;
        ListNode* cur = head;
        ListNode* tail = NULL;
        int n = 0;
        while(cur)
        {
            n++;
            tail = cur; // 循环结束后指向尾节点
            cur = cur->next;
        }
        k = k%n;  // 改为小于n的数，注意是从后往前数，所以后边循环要改成n-k
        tail->next = head; // 尾节点又指向头节点，形成一个环
        cur = head;  // 从头开始循环
        for (int i=0;i<n-k-1;i++)  // 到正数k-1个节点
        {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Rotate-List/Rotate-List.py)
###  方法一：直接法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head==None or k<=0:
            return head
        temp = head
        n = 0
        while temp:
            n+=1
            temp = temp.next
        k = k%n
        temp = head
        for i in range(k):
            temp = self.rightMove(temp)
        return temp
    
    def rightMove(self,head):
        if head==None or head.next==None:
            return head
        prev = None
        cur = head
        temp = head
        while cur.next:
            prev = cur
            cur = cur.next
        prev.next = cur.next
        cur.next = temp
        return cur
```
 
### 方法一改进版  
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head==None or k<=0:
            return head
        cur = head
        tail = None
        n = 0
        while cur:
            n+=1
            tail = cur
            cur = cur.next
        k = k%n
        tail.next = head
        cur = head
        for i in range(n-k-1):
            cur = cur.next
        head = cur.next
        cur.next = None
        return head
```
# 参考

  -  [剑指offer-46题-左旋转字符串](https://github.com/bryceustc/CodingInterviews/blob/master/LeftRotateString/README.md)

