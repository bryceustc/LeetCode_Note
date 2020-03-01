# 题目描述:  用队列实现栈

使用队列实现栈的下列操作：

  - push(x) --元素 x 入栈
  - pop() -- 移除栈顶元素
  - top() -- 获取栈顶元素
  - empty() --返回栈是否为空

**注意:**
    
- 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
- 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque (双端队列) 来模拟一个队列 , 只要是标准的队列操作即可。
- 假设所有操作都是有效的 (例如, 对一个空的栈不会调用 pop 或者 top 操作)。


# 解题思路:
采用模拟法，因为栈和队列的存储方式是完全相反的，所以这里用到两个队列。

当有新元素要push时，用一个队列暂时存储之前的栈，另一个队列pop空，先压入新元素，再把暂时存储之前的栈的队列再一次push进队列中。

这样，队列中的元素顺序就是栈结构的顺序了。因为原始的queue是先进先出，所以要通过queue实现栈，在每一次push进新元素x时，需将前面的元素移到x的后面，可以巧妙地使用q.push(q.front()); q.pop(); 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Implement-Stack-Using-Queues.cpp):
###  两个队列
```c++
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = q2.front();
        q2.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();
    }
private:
    queue<int> q1,q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
### 一个队列
```c++
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        // 把前边n-1个元素放到后边
        for (int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private :
    queue<int> q;
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Implement-Stack-Using-Queues/Implement-Stack-Using-Queues.py)
###  一个队列
```python
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        for i in range(len(self.q)-1):
            self.q.append(self.q.pop(0))

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        n = len(self.q)
        return n==0
```

# 参考
