# 题目描述:  两数相加 II

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

**示例:**
```
输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
```
  
# 解题思路:
  用 stack 保存链表，再从 stack 中取出来，就是数字从低位到高位访问了。
  
  (逆序处理，似乎一般都会用到栈，一个小tips)
# 时间复杂度：
  O(max(m,n)) 其中 m 与 n 分别为两个链表的长度。我们需要遍历每个链表
# 空间复杂度
  O(m+n)
  
# 代码

### 方法一：使用栈
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(-1);
        stack<int> s1,s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int a=0,b=0,carry=0,sum=0;
        while(!s1.empty()||!s2.empty()||carry>0)
        {
            if (s1.empty())
                a=0;
            else
            {
                a=s1.top();
                s1.pop();
            }
            if (s2.empty())
                b=0;
            else
            {
                b=s2.top();
                s2.pop();
            }

            sum = a+b+carry;
            carry = sum/10;
            //头插法建表
            ListNode* temp = new ListNode(sum%10);
            temp->next = dummyhead->next;
            dummyhead->next = temp;
        }
        ListNode* res =dummyhead->next;
        // 释放dummy防止内存泄露
        delete dummyhead;
        return res;
    }
};
```
###  方法二：反转链表
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(-1);
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int a=0,b=0,sum=0,carry=0;
        while(l1||l2||carry>0)
        {
            if (l1==NULL) a=0;
            else
            {
                a=l1->val;
                l1=l1->next;
            }
            if (l2==NULL) b=0;
            else
            {
                b=l2->val;
                l2=l2->next;
            }
            sum = a+b+carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            temp->next = dummyhead->next;
            dummyhead->next = temp;
        }
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }

    ListNode* reverseList(ListNode* head)
    {
        if (head==NULL||head->next==NULL)
            return head;
        else
        {
            ListNode* newhead = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return newhead;
        }
    }
    // ListNode* reverseList(ListNode* head)
    // {
    //     if (head==NULL || head->next == NULL)
    //         return head;
    //     ListNode* pre = NULL;
    //     ListNode* cur = head;
    //     ListNode* temp = head->next;
    //     while(cur)
    //     {
    //         temp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = temp;
    //     }
    //     return pre;
    // }
};
```
