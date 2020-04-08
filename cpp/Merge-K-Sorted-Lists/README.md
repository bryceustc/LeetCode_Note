# 题目描述:  合并K个排序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。


**示例 :**
```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```

# 解题思路:
1. 将合并 k个链表的问题转化成合并 2 个链表 k-1次

2. 
# 时间复杂度：
1. O(n\*k) 

我们可以在 O(n)的时间内合并两个有序链表，其中 n是两个链表的总长度。

把所有合并过程所需的时间加起来，我们可以得到：
# 空间复杂度
1. O(1)
  
# 代码
### 合并两个链表k-1次
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        if (k==1) return lists[0];
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        ListNode* res;
        ListNode* l1 = lists[0];
        ListNode* l2 = lists[1];
        for (int i=1;i<k;i++)
        {
            l2 = lists[i];
            while(l1!=NULL&&l2!=NULL)
            {
                if (l1->val<l2->val)
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
            if (l1==NULL) temp->next = l2;
            if (l2==NULL) temp->next = l1;
            l1 = dummyHead->next;
            temp = dummyHead;
        }
        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
```
