/// Source : https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
/// Author : bryce
/// Time   : 2019-11-16

/*
思路：
这道题让我们以每k个为一组来翻转链表，实际上是把原链表分成若干小段，然后分别对其进行翻转，那么肯定总共需要两个函数，一个是用来分段的，
一个是用来翻转的，以题目中给的例子来看，对于给定链表 1->2->3->4->5，一般在处理链表问题时，大多时候都会在开头再加一个 dummy node，
因为翻转链表时头结点可能会变化，为了记录当前最新的头结点的位置而引入的 dummy node，加入 dummy node 后的链表变为 0->1->2->3->4->5，如果k为3
的话，目标是将 1,2,3 翻转一下，那么需要一些指针，pre 和 next 分别指向要翻转的链表的前后的位置，然后翻转后 pre 的位置更新到如下新的位置：

#####################
0->1->2->3->4->5
|        |  |
pre     cur next

0->3->2->1->4->5
   |     |  |
  cur   pre next
       (last)
 0->3->2->1->4->5
          |  |  |
         pre cur next       
#####################

以此类推，只要 cur 走过k个节点，那么 next 就是 cur->next，就可以调用翻转函数来进行局部翻转了，注意翻转之后新的 cur 和 pre 的位置都不同了，
那么翻转之后，cur 应该更新为 pre->next，而如果不需要翻转的话，cur 更新为 cur->next，代码如下所示：

时间复杂度：
遍历一遍链表，O(L)
空间复杂度：
O(1)
*/
//   C++ Solution 1:
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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* dummyHead = new ListNode(0);
      ListNode* pre = dummyHead;
      dummyHead->next = head;
      ListNode* cur = head;
      ListNode* res;
      if (head != NULL || k==1)
      {
        return head;
      }
      for (int i=1;cur!= NULL;++i)
      {
        if (i%k==0)
        {
          ListNode* next = cur->next;
          pre = reverseOneGroup(pre, next);
          cur = pre->next;
        }
        else
        {
          cur = cur->next;
        }
      }
      res = dummyHead->next;
      delete dummyHead;
      return res;
      }
  
    ListNode* reverseOneGroup(ListNode* pre, ListNode* next)
    {
      ListNode* last = pre->next;
      ListNode* cur = last->next;
      while(cur!=next)
      {
        last->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = last->next;
      }
      return last;
    }
  };
/*
我们也可以在一个函数中完成，首先遍历整个链表，统计出链表的长度，然后如果长度大于等于k，交换节点，当 k=2 时，每段只需要交换一次，当 k=3 时，
每段需要交换2此，所以i从1开始循环，注意交换一段后更新 pre 指针，然后 num 自减k，直到 num<k 时循环结束：
*/

// C++ Solution 2:
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
        dummy->next = head;
        int num = 0;
        while (cur = cur->next) ++num;
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
