# 题目描述:  验证栈序列

给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

**示例 1:**
```
输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```
**示例 2:**
```
输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
```

**提示** 
  1. 0 <= pushed.length == popped.length <= 1000
  2. 0 <= pushed[i], popped[i] < 1000
  3. pushed 是 popped 的排列。

# 解题思路:
采用模拟法，借助一个辅助的栈，遍历压栈的顺序，依次放进辅助栈中。

对于每一个放进栈中的元素，栈顶元素都与出栈的popIndex对应位置的元素进行比较，是否相等，相等则popIndex++，再判断，直到为空或者不相等为止。

具体入栈出栈的操作模拟如下：
  ![1](https://github.com/bryceustc/CodingInterviews/blob/master/StackPushPopOrder/Images/1.png)
  ![2](https://github.com/bryceustc/CodingInterviews/blob/master/StackPushPopOrder/Images/2.png)
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Validate-Stack-Sequences.cpp):
## [Python](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Validate-Stack-Sequences/Validate-Stack-Sequences.py)

###  模拟法
```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        if (n!=m) return false;
        stack<int> s;
        int index = 0;
        for (int i=0;i<n;i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[index])
            {
                s.pop();
                index++;
            }
        }
        return s.empty();
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Hand-Of-Straights/Hand-Of-Straights.py)
###  模拟法
```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        n = len(pushed)
        m = len(popped)
        if n!=m:
            return False
        s = []
        index = 0
        for i in range(n):
            s.append(pushed[i])
            while len(s)>0 and s[-1]==popped[index]:
                s.pop()
                index+=1
        return len(s)==0
```

# 参考

  -  [剑指Offer-31-栈的压入、弹出元素](https://github.com/bryceustc/CodingInterviews/blob/master/StackPushPopOrder/README.md)
