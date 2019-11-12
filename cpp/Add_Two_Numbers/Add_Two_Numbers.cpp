
/// Source : https://leetcode.com/problems/add-two-numbers/description/
/// Author : bryce
/// Time   : 2019-10-13

#include <iostream>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/// Create new LinkedList for result
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum = new ListNode(0);  //新建头结点，value为0
        ListNode *l3=sum;
        int carry = 0, val1 = 0, val2 = 0, sum_val = 0;    //carry用于存储进位，sum_val存储相加                   
        while(l1!=NULL||l2!=NULL)            //三种情况：都不为空链表 1、等长，2、不等长； 有一个为空链表；
        {
            val1 = (l1!=NULL)?l1->val:0;
            val2 = (l2!=NULL)?l2->val:0;
            sum_val = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry)/10; //进位为0或大于1
            
            l3->next = new ListNode (sum_val);
            l3 = l3->next;
            
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        
        if(carry >= 1)
        {
            l3->next = new ListNode(carry);   //不要忽略最后一位的进位
        }
        
        return sum->next;                  //返回除头节点以外数
        
    }
};
int main()
{   
    
    return 0;
}
