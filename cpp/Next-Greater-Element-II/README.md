# 题目描述:  下一个更大元素 II

给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例：
```
输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
```
# 解题思路:
  单调不增栈
  
# 代码

###  
注意如果不是循环数组，就写成如下形式：
```c++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> s;
        int i =0;
        while(i<n)
        {
            if (s.empty()||nums[i]<nums[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int t = s.top();
                s.pop();
                res[t] = nums[i];
            }
        }
        return res;
    }
};
```

循环数组形式：
```c++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = nums.size();
        vector<int> res(n,-1);
        int i = 0;
        stack<int> s;
        // 循环数组，相当于复制两次数组，遍历两次，一般环形利用取模运算来实现
        while(i<2*n)
        {
            if (s.empty() || nums[i%n] <= nums[s.top()])
            {
                s.push(i%n);
                i++;
            }
            else
            {
                int t = s.top();
                s.pop();
                // 只用考虑出栈的元素，在栈里边的不用考虑
                res[t] = nums[i%n];
            }
        }
        return res;
    }
};
```
