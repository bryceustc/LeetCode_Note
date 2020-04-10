# 题目: 旋转数组

## 题目描述：
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

**示例1：**
 ```
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
 ```

**示例2：**
 ```
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
 ```

# 解题思路:
  翻转：YX=(X<sup>T</sup> Y<sup>T</sup>)<sup>T</sup>
# 时间复杂度：
O(n)
# 空间复杂度
 O(1)
# 代码
###  
```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n-k%n;
        reverse(nums.begin(),nums.begin()+m);
        reverse(nums.begin()+m,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
```

