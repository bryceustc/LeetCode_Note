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

2. 归并排序的思想，分治。

- 将 k个链表配对并将同一对中的链表合并
- 第一轮合并以后， k 个链表被合并成了 k/2个链表，平均长度为 2N/k ，然后是 k/4个链表， k/8个链表等等
- 重复这一过程，直到我们得到了最终的有序链表

因此，我们在每一次配对合并的过程中都会遍历几乎全部N个节点，并重复这一过程
# 时间复杂度：
1. O(kn\*k) 

我们可以在 O(n)的时间内合并两个有序链表，其中 n是两个链表的总长度。

把所有合并过程所需的时间加起来，我们可以得到：

2. O(knlogk)
# 空间复杂度
1. O(1)

2. O(logk) 递归需要O(logk)栈空间
  
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
        if (k==0) return NULL;
        if (k==1) return lists[0];
        ListNode* res = lists[0];
        for (int i=1;i<k;++i)
        {
            ListNode* l1 = res;
            ListNode* l2 = lists[i];
            res = merge2Lists(l1,l2);
        }
        return res;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* l3 = dummyhead;
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        while(l1!=NULL&&l2!=NULL)
        {
            if (l1->val <= l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        if (l2==NULL) l3->next = l1;
        if (l1==NULL) l3->next = l2;
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }
};
```
### 归并排序的思想
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
        if (k==0) return NULL;
        if (k==1) return lists[0];
        ListNode* res;
        int mid = k/2;
        auto left = vector<ListNode*> (lists.begin(), lists.begin()+mid);  // 构造函数中的区间是左闭右开的,所以是不包括mid的
        auto right = vector<ListNode*> (lists.begin()+mid,lists.end());  
        ListNode* l1 = mergeKLists(left);
        ListNode* l2 = mergeKLists(right);
        res = mergeTwoLists(l1,l2);
        return res;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        ListNode* res;
        while(l1&&l2)
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
        if (l1==NULL) temp->next=l2;
        if (l2==NULL) temp->next=l1;
        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
```
