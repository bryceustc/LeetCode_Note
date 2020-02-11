# 题目描述:  相交链表

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)
在节点 c1 开始相交。
    
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_1.png)

**示例 1:**
```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```
  
  ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_2.png)

**示例 2:**
```
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```

  ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_3.png)

**示例 3:**
```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
```


# 解题思路:
此题与剑指offer第52题题目一类似

方法一：暴力遍历

方法二：找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走（因为2个链表用公共的尾部）。如果存在共同节点的话，那么从该节点，两个链表之后的元素都是相同的。 也就是说两个链表从尾部往前到某个点，节点都是一样的。

 
# 时间复杂度：
  方法一：O(nm) 
  
  方法二：O(n+m)
# 空间复杂度
  方法一：O(1)
  
  方法二：O(1)
  
  
# 代码

## [C++](./Intersection-Of-Two-Linked-Lists.cpp):

###  方法一： 暴力遍历法
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB == NULL) return NULL;
        ListNode* p = headA;
        ListNode* q = headB;
        while(p)
        {
            q = headB;
            while(q)
            {
                if (p->val==q->val)
                {
                    return p;
                }
                else
                {
                    q = q->next;
                }
            }
            p = p->next;
        }
        return NULL;
    }
};
```

###  方法二： 
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
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Intersection-Of-Two-Linked-Lists/Intersection-Of-Two-Linked-Lists.py)
###  方法一：暴力遍历法
```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def FindFirstCommonNode(self, l1, l2):
        # write code here
        if l1==None or l2 == None:
            return None
        p = l1
        q = l2
        while p:
            q = l2
            while q:
                if p.val==q.val:
                    return p
                else:
                    q = q.next
            p = p.next
        return None
```
### 方法二 ：
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA==None or headB == None:
            return None
        p = headA
        q = headB
        n =0
        m=0
        while p:
            n+=1
            p = p.next
        while q:
            m+=1
            q = q.next
        p = headA
        q = headB
        k = 0
        if n>=m:
            k = n-m
        else:
            p = headB
            q = headA
            k = m-n
        for i in range(k):
            p = p.next
        while p and q and p!=q:
            p = p.next
            q = q.next
        res = p
        return res
```

# 参考
  - [剑指offer第52题-两个链表的第一个公共节点](https://github.com/bryceustc/CodingInterviews/blob/master/FirstCommonNodesInLists/README.md)

