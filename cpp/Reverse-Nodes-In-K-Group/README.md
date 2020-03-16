# 题目描述:  K 个一组翻转链表

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。


**示例 :**
```
给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
```

# 解题思路:
首先遍历整个链表，统计出链表的长度，然后如果长度大于等于k，交换节点，当 k=2 时，每段只需要交换一次，当 k=3 时，
每段需要交换2此，所以i从1开始循环，注意交换一段后更新 pre 指针，然后 num 自减k，直到 num<k 时循环结束：
# 时间复杂度：
  O(n\*k)
# 空间复杂度
  O(1)
  
# 代码
### 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* pre = dummyhead;
        dummyhead->next = head;
        ListNode* cur = head;
        int num = 0;
        while(cur)
        {
            cur = cur->next;
            num++;
        }
        // 画图理解
        while(num>=k)
        {
            cur = pre->next;
            for (int i=1;i<k;i++)
            {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            num-=k;
        }
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }
};
```
