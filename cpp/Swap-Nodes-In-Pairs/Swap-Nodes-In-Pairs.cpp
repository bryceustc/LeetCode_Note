  
/// Source : https://leetcode-cn.com/problems/swap-nodes-in-pairs/
/// Author : bryce
/// Time   : 2019-11-15

/*
思路：
基本的链表操作题，可以用迭代和递归两种方法实现，迭代方法：
1. 新建虚拟保护节点dummyHead，并且dummyHead的next指针指向head,并新建temp指针指向dummyHead
2. 新建s1,s2,s三个指针，分别指向temp后三个指针，即分别指向next指针，next的next指针，next的next的next指针
3. 根据画图链表，可以分析出要交换相邻两结点，则temp的next指针指向s2,而s2的next指针指向s1,s1的next指针指向s,
4. 然后再将temp指向s2,进行循环，重复上述步骤，直至temp的next为空或temp的next的next为空
时间复杂度：
遍历一遍链表，时间复杂度为O(L)
*/


// C++ Solution 1:
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode* dummyHead = new ListNode(0);
      ListNode* temp = dummyHead;
      dummyHead->next = head;
      ListNode* res;
      while(temp->next != NULL && temp->next->next != NULL)
      {
        ListNode* s1 = temp->next;
        ListNode* s2 = s1->next;
        ListNode* s = s2->next;
        temp->next = s2;
        s2->next = s1;
        s1->next = s;
        temp = temp->next->next;//temp = s2;
      }
      res = dummyHead->next;
      delete dummyHead;
      return res;
    }
};
/*
递归的写法就更简洁了，实际上利用了回溯的思想，递归遍历到链表末尾，然后先交换末尾两个，然后依次往前交换：
终止条件：head 为空指针或者 next 为空指针，也就是当前无节点或者只有一个节点，无法进行交换
*/

// C++ Solution 2:
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(head == NULL || head->next == NULL)
        return head;
      ListNode* res = head->next;
      head->next = swapPairs(head->next->next);
      res->next = head;
      return res;
    }
};
