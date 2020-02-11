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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        ListNode* p = headA;
        ListNode* q = headB;
        int n=0,m=0;
        while(p)
        {
            n++;
            p=p->next;
        }
        while(q)
        {
            m++;
            q=q->next;
        }
        p = headA;
        q = headB;
        int k = 0;
        if (n>=m)
        {
            k=n-m;
        }
        else
        {
            k=m-n;
            p=headB;
            q=headA;
        }
        for (int i=0;i<k;i++)
        {
            p = p->next;
        }
        while(p && q && p!=q)
        {
            p = p->next;
            q = q->next;
        }
        ListNode* res = p;
        return res;
    }
};
