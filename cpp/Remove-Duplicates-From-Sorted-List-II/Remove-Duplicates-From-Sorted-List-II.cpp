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
