/// Source : https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
/// Author : bryce
/// Time   : 2019-11-10

/*
思路:
(I)(两次遍历)
1.第一次遍历求出链表长度。
2.第二次遍历删掉指定结点。
3.注意删除头结点的特殊情况。

时间复杂度:遍历两次链表，故空间复杂度为 O(L)。
空间复杂度:仅需要定义常数个指针变量，故空间复杂度为 O(1)
*/

// C++ Solution 1:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int len = 0;
      int m = 0;
      for (ListNode* temp = head; temp != NULL; temp = temp->next)
      {
        len++;
      }
      if (n == len)
        return head -> next;  //特殊情况n为链表总长度，删除头结点
      for(ListNode* temp = head; temp != NULL; temp = temp->next)
      {
        m++;
        if (m == len - n)
        {
          temp -> next = temp -> next -> next;  //删除指定节点
          break;
        }
      }
      return head;
    }
};

/*
思路:
(II)(一次遍历)
    我们可以设想假设设定了双指针p和q的话，当q指向末尾的NULL，p与q之间相隔的元素个数为n时，
那么删除掉p的下一个指针就完成了要求。

1.设置虚拟节点dummyHead指向head。
2.移动q，直到p与q之间相隔的元素个数为n。
3.同时移动p与q，直到q指向的为NULL，将p的下一个节点指向下下个节点。

时间复杂度:遍历两次链表，故空间复杂度为 O(L)。
空间复杂度:仅需要定义常数个指针变量，故空间复杂度为 O(1)
*/

// C++ Solution 2:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);   // 设置保护节点了删除头结点的时候能和删除其他结点一样处理，不用特殊处理头结点
        dummyHead -> next = head;
        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        for (int i = 0; i<n;i++)
        {
            q = q -> next;
        }
        while (q->next != NULL)
        {
            p = p -> next;
            q = q -> next;
        }
        p -> next = p -> next -> next;
        ListNode* res = dummyHead -> next;
        delete dummyHead;
        return res;
    }
};
