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
