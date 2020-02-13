# 题目描述:  相交链表

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)
在节点 c1 开始相交。
    
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_1.png)

**示例 1:**
```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```
  
  ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_2.png)

**示例 2:**
```
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```

  ![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_3.png)

**示例 3:**
```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
```


# 解题思路:
此题与剑指offer第30题题目一样
  
  思路：利用两个栈，一个数据栈，一个作为存储最下元素的辅助栈
 
# 时间复杂度：
  O(1) 
# 空间复杂度
  O(n)
  
  
# 代码

## [C++](./Min-Stack.cpp):

###  
```c++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack1.push(x);
        if (stack2.empty() || x < stack2.top())
        {
            stack2.push(x);
        }
        else
        {
            int y = stack2.top();
            stack2.push(y);
        }
    }
    
    void pop() {
        if (stack1.size()>0 && stack2.size()>0)
        {
            stack1.pop();
            stack2.pop();
        }
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Min-Stack/Min-Stack.py)
###  
```python
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        self.stack1.append(x)
        if len(self.stack2)==0 or x < self.stack2[-1]:
            self.stack2.append(x)
        else:
            a = self.stack2[-1]
            self.stack2.append(a)

    def pop(self) -> None:
        if len(self.stack1) > 0 and len(self.stack2) > 0:
            self.stack1.pop()
            self.stack2.pop()

    def top(self) -> int:
        return self.stack1[-1]

    def getMin(self) -> int:
        return self.stack2[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```

# 参考
  - [剑指offer第30题-包含min函数的栈](https://github.com/bryceustc/CodingInterviews/blob/master/MinInStack/README.md)


