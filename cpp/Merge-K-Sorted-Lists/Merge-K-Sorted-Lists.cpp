/// Source : https://leetcode-cn.com/problems/merge-k-sorted-lists/
/// Author : bryce
/// Time   : 2019-11-14

/*
思路：
将合并 k 个链表的问题转化成合并 2 个链表k-1 次。类似两个有序链表合并排序，
1. 先判断是否为空，为空则返回空指针
2. 判断lists长度，如果为1，则直接返回lists[0]
3. 然后新建保护结点dummyHead,并令temp指针指向dummyHead
4. 采取与两个有序链表l1,l2合并的方法，然后按循环两个依次合并，先指向lists[0]的l1与指向lists[1]的l2合并，将l1指向合并链表再,l2指向下一个lists
5. 重复步骤4 直至跳出循环

时间复杂度：
O(kn)

空间复杂度：
O(1)

*/


// C++ Solution 1:
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;
        ListNode* res;
        int k = lists.size();
        if (lists.empty()) return NULL;
        if (k==1) return lists[0];
        ListNode* l1 = lists[0];
        ListNode* l2 = lists[1];
        for (int i = 1;i<k;++i)
        {
            l2 = lists[i];
            while(l1!=NULL && l2!=NULL)
            {
                if(l1->val < l2->val)
                {
                    temp -> next = l1;
                    l1 = l1->next;
                }
                else
                {
                    temp -> next = l2;
                    l2 = l2->next;
                }
                temp = temp->next;
            }
            if (l1==NULL)
            {
                temp->next = l2;
            }
            else
            {
                temp->next = l1;
            }
            l1 = dummyHead->next;
            temp = dummyHead;           
        }
        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
