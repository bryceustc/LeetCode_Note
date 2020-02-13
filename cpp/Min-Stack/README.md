# 题目描述:  最小栈

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

   - push(x) -- 将元素 x 推入栈中。
   - pop() -- 删除栈顶的元素。
   - top() -- 获取栈顶元素。
   - getMin() -- 检索栈中的最小元素。

**示例 :**
```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
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
