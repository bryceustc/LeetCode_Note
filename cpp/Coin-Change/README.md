# 题目描述:  零钱兑换

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。


# 解题思路:
用dp[i] 来表示组成i块钱，需要最少的硬币数，那么

1. 第j个硬币我可以选择不拿 这个时候， 硬币数 = dp[i]

2. 第j个硬币我可以选择拿 这个时候， 硬币数 = dp[i - coins[j]] + 1

  - 和背包问题不同， 硬币是可以拿任意个

  - 对于每一个 dp[i] 我们都选择遍历一遍 coin， 不断更新 dp[i]

PS：为啥 dp 数组初始化为 amount + 1 呢，因为凑成 amount 金额的硬币数最多只可能等于 amount（全用 1 元面值的硬币），所以初始化为 amount + 1 就相当于初始化为正无穷，便于后续取最小值。


# 时间复杂度：
  O(n)
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Coin-Change.cpp):
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

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Coin-Change/Coin-Change.py)
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
