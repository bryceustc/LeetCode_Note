/// Source : https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
/// Author : bryce
/// Time   : 2019-11-16

/*
思路：
基本的链表操作题，可以用迭代和递归两种方法实现，迭代方法：
1. 新建虚拟保护节点dummyHead，并且dummyHead的next指针指向head,并新建temp指针指向dummyHead
2. 新建s1,s2,s三个指针，分别指向temp后三个指针，即分别指向next指针，next的next指针，next的next的next指针
3. 根据画图链表，可以分析出要交换相邻两结点，则temp的next指针指向s2,而s2的next指针指向s1,s1的next指针指向s,
4. 然后再将temp指向s2,进行循环，重复上述步骤，直至temp的next为空或temp的next的next为空
时间复杂度：
O(kn)
空间复杂度：
O(1)
*/
