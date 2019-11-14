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


// C++ Solution 2: (分治法)
/*
思路：
k个链表先划分为合并两个 k/2 个链表的任务，再不停的往下划分，直到划分成只有一个或两个链表的任务，开始合并。
举个例子来说比如合并6个链表，那么按照分治法，首先分别合并0和3，1和4，2和5。这样下一次只需合并3个链表，再合并1和3，最后和2合并就可以了。
代码中的mid是通过 (k+1)/2 计算的，这里为啥要加1呢，这是为了当k为奇数的时候，k能始终从后半段开始，比如当 n=5 时，那么此时 k=3，则0和3合并，
1和4合并，最中间的2空出来。当n是偶数的时候，加1也不会有影响，比如当 n=4 时，此时 k=2，那么0和2合并，1和3合并，完美解决问题



*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res;
        int k = lists.size();
        if (lists.empty())
            return NULL;
        if (k ==1)
            return lists[0];
        int mid = k/2;
        auto left = vector<ListNode*> (lists.begin(),lists.begin()+mid);
        auto right = vector<ListNode*>(lists.begin()+mid,lists.end());
        ListNode* l1 = mergeKLists(left);
        ListNode* l2 = mergeKLists(right);
        res = merge2Lists(l1,l2);
        return res;
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;
        while (l1!=NULL && l2!=NULL)
        {
            if (l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1==NULL)
            temp->next = l2;
        else
            temp->next = l1;
        return dummyHead->next;
    }
};
        
