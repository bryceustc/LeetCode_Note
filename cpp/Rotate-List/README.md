# 题目描述:  旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

**示例 1:**
```
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
```

**示例 2:**
```
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```

  
# 解题思路:
思路一：思路与左旋转字符串类似，利用画图理解，并定义一个向右移动一位的函数rightMove，注意空指针的情形，然后注意k可能大于链表长度，所以这时候需要取一下余，不然会超时

思路二：不需要定义向右移动一位的函数，说是循环旋转，但其实本质上是将尾部向前数第K个元素作为头，原来的头接到原来的尾上。理解这句话：
  - 先将链表闭合成环
  - 找到相应的位置断开这个环，确定新的链表头和链表尾
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Rotate-List.cpp):

###  方法一： 直接法
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k<=0)
            return head;
        ListNode* temp = head;
        int n = 0;//链表长度
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        ListNode* dummyhead = new ListNode(-1);
        temp = head;
        k = k%n;
        for (int i=0;i<k;i++)
        {
            temp = rightMove(temp);
        }
        dummyhead->next = temp;
        return dummyhead->next;
    }
    ListNode* rightMove(ListNode* head)
    {
        if (head==NULL || head->next==NULL) 
            return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp = head;
        while(cur->next!=NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        cur->next = temp;
        return cur;
    }
};
```

###  方法一改进版：
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k<=0)
            return head;
        ListNode* cur = head;
        ListNode* tail = NULL;
        int n = 0;
        while(cur)
        {
            n++;
            tail = cur; // 循环结束后指向尾节点
            cur = cur->next;
        }
        k = k%n;  // 改为小于n的数，注意是从后往前数，所以后边循环要改成n-k
        tail->next = head; // 尾节点又指向头节点，形成一个环
        cur = head;  // 从头开始循环
        for (int i=0;i<n-k-1;i++)  // 到正数k-1个节点
        {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Rotate-List/Rotate-List.py)
###  方法一：直接法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head==None or k<=0:
            return head
        temp = head
        n = 0
        while temp:
            n+=1
            temp = temp.next
        k = k%n
        temp = head
        for i in range(k):
            temp = self.rightMove(temp)
        return temp
    
    def rightMove(self,head):
        if head==None or head.next==None:
            return head
        prev = None
        cur = head
        temp = head
        while cur.next:
            prev = cur
            cur = cur.next
        prev.next = cur.next
        cur.next = temp
        return cur
```
 
### 方法一：res=''初始化的问题,res得声明为全局变量  
```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res = ''

        def factorial(num):
            res = 1
            while num > 0:
                res *= num
                num -= 1
            return res

        def DFS(visited, level, n, k, res):
            if level == n:
                return res
            ps = factorial(n - 1 - level)
            for i in range(1, n + 1):
                if visited[i] == 1:
                    continue
                if 0 < ps < k:
                    k -= ps
                    continue
                res += str(i)  ## 递归到底时已经是第 k 个排列，res 也是字符串的形式
                visited[i] = 1
                return DFS(visited, level + 1, n, k, res)

        if n == 0:
            return ""
        visited = [0 for _ in range(n + 1)]
        res = DFS(visited, 0, n, k, res)
        return res
```
# 参考

  -  [46题全排列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations/README.md)
  -  [47题全排列II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations-II/README.md)
  -  [回溯+剪枝](https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/)
  -  [Python合并list为字符串的方法](https://blog.csdn.net/Zx_whu/article/details/61926655)
  -  [Python字符串拼接总结](https://segmentfault.com/a/1190000015475309)
  -  [Python中的NULL和None](https://blog.csdn.net/songyunli1111/article/details/75145533)但python是把0，空字符串‘ ’，空列表[]和None都看作False，把其他数值和非空字符串都看作True
  -  [康托展开](https://baike.baidu.com/item/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80) 
  -  [Python3：可变对象和不可变对象](https://blog.csdn.net/Artprog/article/details/88732987) 
  -  [Python map() 函数](https://www.runoob.com/python/python-func-map.html) 

