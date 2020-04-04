# 题目描述:  每日温度

根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。


例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。


# 解题思路:
  单调不增栈
  
# 代码

###  单调不增栈
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        int i =0;
        vector<int> res(n,0);
        stack<int> s;
        while(i<n)
        {
            if (s.empty() || T[i] <= T[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int t = s.top();
                s.pop();
                res[t] = i-t;  //  注意返回的是两坐标之差
            }
        }
        return res;
    }
};
```
