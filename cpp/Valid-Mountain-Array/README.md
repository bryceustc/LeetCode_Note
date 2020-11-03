# 题目描述:  有效的山脉数组

给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

- A.length >= 3
- 在 0 < i < A.length - 1 条件下，存在 i  使得：
  - A[0] < A[1] < ... A[i-1] < A[i]
  - A[i] > A[i+1] > ... > A[A.length - 1]

**示例 1:**
```
输入：[2,1]
输出：false
```

**示例 2:**
```
输入：[3,5,5]
输出：false
```

  
# 解题思路:

二分查找
 
# 时间复杂度：
  
  O(logn)
  
# 空间复杂度
  O(1)
  
# 代码
```c++
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3) return false;
        int l = 0, r = n-1;
        while(l < n - 2 && A[l] < A[l+1]) l++;
        while(r > 1 && A[r] < A[r-1]) r--;
        return l == r;
    }
};
```
