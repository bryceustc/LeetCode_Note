# 题目描述:  盛最多水的容器

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
  
# 解题思路:
  - 暴力法
  
  - 双指针
 
# 时间复杂度：
  最优O(n)
# 空间复杂度
  O(1)
  
# 代码

## [C++](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Container-With-Most-Water/Container-With-Most-Water.cpp):

###  双指针
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n<2) return 0;
        int res = 0;
        int i=0,j=n-1;
        while(i<j)
        {
            int h = min(height[i],height[j]);
            int w = j-i;
            res = max(res, h*w);
            if (height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};
```
# 参考

  -  [双指针正确性的证明](https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/)

