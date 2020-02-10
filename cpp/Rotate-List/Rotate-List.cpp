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
