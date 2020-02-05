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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* prev = p;
        ListNode* cur = head;
        ListNode* del = NULL;
        while(cur)
        {
            if (cur->val==val)
            {
                prev->next = cur->next;
                del = cur;
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
            if (del)
            {
                delete del;
                del = NULL;
            }
        }
        ListNode* res = p->next;
        delete p;
        return res;
    }
};
