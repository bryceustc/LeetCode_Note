# 题目描述:  环形链表

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

**示例 :**
```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

# 解题思路:
  快慢指针:快指针每次走2步，慢指针每次走1步，当两者相遇说明一定有环。
  
# 代码

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
    bool hasCycle(ListNode *head) {
        if (head==NULL || head->next==NULL) return false;
        ListNode *p = head;
        ListNode *q = head;
        while(q!=NULL && q->next!=NULL)
        {
            p = p->next;
            q = q->next->next;
            if (p==q)
            {
                return true;
            }
        }
        return false;
    }
};
```
