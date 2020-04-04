## Leetcode 单调栈问题总结

单调栈主要回答这样的几种问题

  - 比当前元素更大的下一个元素
  - 比当前元素更大的前一个元素
  - 比当前元素更小的下一个元素
  - 比当前元素更小的前一个元素

 单调栈的一大优势就是**线性的时间复杂度**，所有的元素只会进栈一次，而且一旦出栈后就不会再进来了。

   **单调递增栈可以找到左起第一个比当前数字小的元素**。比如数组 [2 1 4 6 5]，刚开始2入栈，数字1入栈的时候，发现栈顶元素2比较大，将2移出栈，此时1入栈。那么2和1都没左起比自身小的数字。然后数字4入栈的时候，栈顶元素1小于4，于是1就是4左起第一个小的数字。此时栈里有1和4，然后数字6入栈的时候，栈顶元素4小于6，于是4就是6左起第一个小的数字。此时栈里有1，4，6，然后数字5入栈的时候，栈顶元素6大于5，将6移除，此时新的栈顶元素4小于5，那么4就是5左起的第一个小的数字，最终栈内数字为1，4，5。

   同样的道理，**单调递减栈可以找到左起第一个比当前数字大的元素**。
   
 ### LeetCode 42：接雨水
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

![](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/rainwatertrap.png)

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

分析：

必须两边高，中间低可以装下水，就可以使用一个单调递减栈，将递减的边界存进去，一旦发现当前的数字大于栈顶元素了，那么就有可能会有能装水的地方产生。此时我们当前的数字是右边界，我们从栈中至少需要有两个数字，才能形成一个坑槽，先取出的那个最小的数字，就是坑槽的最低点，再次取出的数字就是左边界，我们比较左右边界，取其中较小的值为装水的边界，然后此高度减去水槽最低点的高度，乘以左右边界间的距离就是装水量了。由于需要知道左右边界的位置，所以我们虽然维护的是递减栈，但是栈中数字并不是存递减的高度，而是递减的高度的坐标。

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        int res = 0;
        stack<int> s;
        int i=0;
        while(i<n)
        {
            if(s.empty() || height[i] < height[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int t = s.top();
                s.pop();
                if (s.empty())
                {
                    continue;
                }
                int h = min(height[s.top()],height[i]) -  height[t];
                int w = i-s.top()-1;
                res += h*w;
            }
        }
        return res;
    }
};
```

### LeetCode 84：柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram_area.png)

分析：就是找两边第一个小于它的值，比如height[i]，以第i根柱子为最矮柱子所能延伸的最大面积，是以i 为中心，向左找第一个小于 heights[i] 的位置 left_i；向右找第一个小于于 heights[i] 的位置 right_i，即最大面积为 heights[i] * (right_i - left_i -1)，如下图所示:

![](https://pic.leetcode-cn.com/441ac778821dc26689b31466bced9f61ec241f092bf7e4f0f8699ef4fa3be1b2-1559826097853.png)
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
                // 出栈是计算以栈顶元素高度为矩形长的最大矩形面积
                int t = s.top();  
                // height[t]高度为最高，寻找左右两端小于高度heights[t]的坐标,右边小于高度t的坐标为i，
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
