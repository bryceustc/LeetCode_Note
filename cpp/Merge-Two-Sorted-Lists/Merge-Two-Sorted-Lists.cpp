/// Source : https://leetcode-cn.com/problems/merge-two-sorted-lists/
/// Author : bryce
/// Time   : 2019-11-12

/*
思路:
1.新建保护节点dummyHead,设置temp指针指向dummyHead
2.如果当前l1指针指向的节点的值val比l2指针指向节点值小，则令temp的next指针指向l1，并且向后移动l1,否则，temp的next指针指向l2，并且向后移动l2
3.向后移动temp
4.循环上述步骤直至l1或l2为NULL
5.判断如果l1为空，则temp的next指针指向l2,否则指向l1


时间复杂度：
两个链表各遍历一次，所以时间复杂度为O(n+m)
空间复杂度：
O(1)。迭代过程中产生几个指针，所需空间为常数级别。
*/

// C++ Solution 1: (线性合并)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* dummyHead = new ListNode(0);
      ListNode* temp = dummyHead;
      ListNode* l3;
      while( l1!=NULL && l2!=NULL)
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
      if (l1!=NULL) 
        temp->next = l1;
      else
        temp->next = l2;
      l3 = dummyHead->next;
      delete dummyHead;
      return l3;
    }
};
/*
递归思路：
可以定义递归操作：
    list[0] + merge(list[1:],list2)   (list[0] < list2[0])
    list[2] + merge(list1,list2[1:])   otherwise
    两个链表头部较小的一部分与剩下的merge操作合并。
时间复杂度：O(m+n)
空间复杂度：O(m+n)
*/


// C++ Solution 2: (递归)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
