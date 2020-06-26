# 题目描述:  移除重复节点

编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

**示例1 :**
```
 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
```
**示例1 :**
```
 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
```

# 解题思路:
一开始理解错题意了，利用哈希来做，链表题注意画图帮助理解.

利用哈希表，依次遍历每一个节点，如果这个节点的值不在于哈希表中，将该节点的值添加到哈希表中，否则将该节点删除
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
# 代码
### 哈希
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        unordered_set<int> s;
        while(cur != NULL) {
            if (s.count(cur->val)){
                cur = cur->next;
            }
            else {
                s.insert(cur->val);
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        pre->next = NULL;
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
```
