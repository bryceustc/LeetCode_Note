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
1.第一次遍历求出链表长度。
2.第二次遍历删掉指定结点。
3.注意删除头结点的特殊情况。

时间复杂度:遍历两次链表，故空间复杂度为 O(L)。
空间复杂度:仅需要定义常数个指针变量，故空间复杂度为 O(1)
*/

// C++ Solution 2:
