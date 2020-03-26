# 题目描述:  柱状图中最大的矩形

给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。


![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram.png)

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram_area.png)

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
**示例 :**
```
输入: [2,1,5,6,2,3]
输出: 10
```
# 解题思路:
  单调栈
  
# 代码

###  
```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        // 单调递增栈，为保证所有元素都出栈，最后加一个0
        heights.push_back(0);
        int n = heights.size();
        int res = 0;
        stack<int> s;
        int i = 0;
        while(i<n)
        {
            if (s.empty() || heights[i] > heights[s.top()])
            {
                s.push(i++);
            }
            else
            {
                // 出栈是计算包含栈顶元素高度的最大矩形面积
                int t = s.top();  
                // 为最高，寻找左右两端小于高度heights[t]的坐标,右边小于高度t的坐标为i，
                // 如果出栈后不为空，则左边小于高度t的坐标为s.top(), 因为维持递增序列，
                // 出栈后下一个栈顶是小于高度t的，为空则说明左边没有小于高度t的
                s.pop();
                int w = 0;
                if (s.empty())
                {
                    w = i;
                }
                else
                {
                    // 注意-1
                    w = i - s.top() - 1;
                }
                res = max(res, heights[t] * w);
            }
        }
        return res;
    }
};
```
### 参考：
   - [详细题解](https://blog.csdn.net/Zolewit/article/details/88863970)
