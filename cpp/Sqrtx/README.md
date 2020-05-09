# 题目描述:  平方根


实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 

**示例 :**
```
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
```
# 解题思路:
二分法
# 时间复杂度：
O(logn)
  
# 空间复杂度
 O(1)
  
# 代码

###  二分法
```c++
class Solution {
public:
    int mySqrt(int x) {
        if (x<=1) return x;
        long left = 0;
        long right = x;
        int res = 0;
        while(left<=right)
        {
            long mid = left + (right-left)/2;
            if (mid*mid<=x) 
            {
                res = mid;
                left = mid+1;
            }
            else
            {
                right = mid -1;
            }
        }
        return res;
    }
};
```

