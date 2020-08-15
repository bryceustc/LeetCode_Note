# 题目描述:  回文链表

请判断一个链表是否为回文链表。

**示例 1:**
```
输入: 1->2
输出: false
```
**示例 2:**
```
输入: 1->2->2->1
输出: true
```
**说明:**
  - 链表至少包含两个节点。
  - 链表中所有节点的值都是唯一的。
  - 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
  - 不要从你的函数中返回任何结果。
  
# 解题思路:
这个是个双指针的解法。需要先将前半段链条反转
 
# 时间复杂度：
   O(n)。
# 空间复杂度
  O(1)
# 代码

###  
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* p = NULL;
        ListNode* pre = NULL;
        while (fast && fast->next != NULL) {
            p = slow;
            slow = slow->next; //快慢遍历
            fast = fast->next->next;

            p->next = pre; //翻转
            pre = p;
        }
        if (fast) {
            slow = slow->next;  //奇数个节点时跳过中间节点
        }
        while(p) {
            if (p->val != slow->val) { //前半部分和后半部分比较
                return false;
            }
            p = p->next;
            slow = slow->next;
        }
        return true;
    }
};
```
