# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        carry = 0
        # dummy head
        sum_val = l3 = ListNode(0)  #引用ListNode类定义一个链表节点并初始化值为0
        while l1 or l2:           #l1或l2不为空就持续执行
            val = carry             
            if l1:              #l1不为空，就把l1的某个节点值相加val再复制给val
                val += l1.val
                l1 = l1.next
            if l2:              #l2不为空，就把l2的某个节点值相加val再复制给val
                val += l2.val
                l2 = l2.next
            l3.next = ListNode(val % 10)
            l3 = l3.next
            carry = val / 10
        if carry > 0:
            l3.next = ListNode(carry)
        return sum_val.next
