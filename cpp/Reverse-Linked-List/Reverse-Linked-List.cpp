// Solution 1:
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
// Solution 2:
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
