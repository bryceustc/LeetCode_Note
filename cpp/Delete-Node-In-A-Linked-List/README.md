# 题目描述:  删除链表中的节点

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中*没有重复出现*的数字。

请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

![1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png)

**示例 1:**
```
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
```
**示例 2:**
```
输入: head = [4,5,1,9], node = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
```
**说明:**
  - 链表至少包含两个节点。
  - 链表中所有节点的值都是唯一的。
  - 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
  - 不要从你的函数中返回任何结果。
  
# 解题思路:
此题与剑指offer第18题删除链表中的节点类似，主要就是理解题意，有一定的创新思维。

思路一：直接删除节点，需要被删除节点的前一个节点，所需时间复杂度O(n)，因为此题，所给函数参数，只有一个node，没有head参数，不可行。

思路二：将后继节点复制到被删除节点，然后删除所要删除节点的后续节点，注意不删除尾节点，时间复杂度O(1)。
 
# 时间复杂度：
   O(1)。
# 空间复杂度
  O(1)
# 代码

## [C++](./Delete-Node-In-A-Linked-List.cpp):

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Delete-Node-In-A-Linked-List/Delete-Node-In-A-Linked-List.py)
###  
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next
```
# 参考
  - [剑指offer第18题-删除链表中的节点](https://github.com/bryceustc/CodingInterviews/blob/master/DeleteDuplicatedNode/README.md)
  - [LeetCode-83题-删除排序链表中的重复元素](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Remove-Duplicates-From-Sorted-List/README.md)
