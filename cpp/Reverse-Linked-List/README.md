# 题目描述:  反转链表

反转一个单链表。

**示例 :**
```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```
**进阶:** 
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
  
# 解题思路:
此题与剑指offer第6题从尾到头打印链表类似

有两种方法：

方法一：非递归方法，利用两个结点指针和一个中间结点指针temp(用来记录当前结点的下一个节点的位置)，分别指向当前结点和前一个结点，每次循环让当前结点的指针域指向前一个结点即可，翻转结束后，记得将最后一个节点的链域置为空。

方法二：递归方法

 
# 时间复杂度：
  假设 n 是列表的长度，时间复杂度是 O(n)。
# 空间复杂度
  方法一：O(1)
  
  方法二：O(n),由于使用递归，将会使用隐式栈空间。递归深度可能会达到 n 层。
# 代码

## [C++](./Reverse-Linked-List.cpp):

###  方法一：非递归法
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next==NULL)
            return head;
        ListNode* p = NULL;
        ListNode* cur = head;
        ListNode* temp = head->next;
        while (cur)
        {
            temp = cur->next; // temp作为中间节点，记录当前节点的下一节点位置
            cur->next = p; // 当前节点指向前一个节点
            p = cur;  // 指针后移
            cur = temp; // 指针后移，处理下一节点
        }
        return p;
    }
};
```
### 方法二：递归法
```c++

```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Reverse-Linked-List/Reverse-Linked-List.py)
###  方法一：非递归法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head==None or head.next==None:
            return head
        p = None
        cur = head
        temp = head.next
        while cur:
            temp = cur.next
            cur.next = p
            p = cur
            cur = temp
        return p
```

### 方法二：非递归法
```python
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums:
            return ""
        # 直接拼接数字，可能导致数值溢出，这是一个隐形的大数问题，需要把数字转换成字符串
        nums = map(str, nums)
        # 把数字m和n拼接为mn，nm，只需要按照字符串大小的比较
        nums.sort(lambda x, y: cmp(y + x, x + y))
        return ''.join(nums).lstrip('0') or '0'
```
# 参考
  - [剑指offer第6题-从尾到头打印链表](https://github.com/bryceustc/CodingInterviews/blob/master/PrintListInReversedOrder/README.md)
  - [C++中 string对象的大小比较](https://blog.csdn.net/jason_cuijiahui/article/details/79038468)
  - [C++ algorithm sort自定义排序](https://blog.csdn.net/v_xchen_v/article/details/76615270)
  - [关于类中重载sort函数的报错问题（解决error: invalid use of non-static member function 'bool Solution::cmp(int, int)'）](https://blog.csdn.net/qq_41562704/article/details/95908736)
  - [python3与python2的不同定义排序](https://leetcode-cn.com/problems/largest-number/solution/python3yu-python2de-bu-tong-ding-yi-pai-xu-by-jixi/)
  - [Python3: 找回sort()中消失的cmp参数](https://www.polarxiong.com/archives/Python3-%E6%89%BE%E5%9B%9Esort-%E4%B8%AD%E6%B6%88%E5%A4%B1%E7%9A%84cmp%E5%8F%82%E6%95%B0.html)
  - [Python map()函数用法](https://www.runoob.com/python/python-func-map.html)
  - [Python sorted()函数用法](https://www.runoob.com/python/python-func-sorted.html) 




