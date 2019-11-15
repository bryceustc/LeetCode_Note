  
/// Source : https://leetcode-cn.com/problems/swap-nodes-in-pairs/
/// Author : bryce
/// Time   : 2019-11-15

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};
