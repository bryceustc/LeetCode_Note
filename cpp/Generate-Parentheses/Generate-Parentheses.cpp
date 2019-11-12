/// Source : https://leetcode-cn.com/problems/generate-parentheses/
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

// C++ Solution 1:
