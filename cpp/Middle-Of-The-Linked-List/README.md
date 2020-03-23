# 题目描述:  链表的中间结点

给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

**示例 :**
```
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
```
# 解题思路:
  1. 直接法
  
  2. 快慢指针:快指针每次走2步，慢指针每次走1步，当fast走到末尾时slow正好走到中间。
  
# 代码

###  直接法
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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* cur = head;
        int n = 0, mid = 0;
        while(cur)
        {
            cur = cur->next;
            n++;
        }
        mid =n/2 +1;
        cur = head;
        for (int i=0;i<mid-1;i++)  // 注意是到mid-1
        {
            cur = cur->next;
        }
        return cur;
    }
};
```

### 快慢指针
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
    ListNode* middleNode(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```

