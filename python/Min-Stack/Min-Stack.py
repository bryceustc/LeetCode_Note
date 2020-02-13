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
