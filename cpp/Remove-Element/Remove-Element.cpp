/// Source : https://leetcode-cn.com/problems/remove-element/
/// Author : bryce
/// Time   : 2019-11-18

/*
思路：
1. 如果nums为空，直接返回0
2. 初始化k = 0,从i=1开始遍历整个数组，如果nums[k]不等于nums[i]，说明没有遇到重复元素，就是新元素，令nums[++k] = nums[i]
3. 返回res = k+1

时间复杂度：
遍历一遍数组，时间复杂度为O(n)

空间复杂度：
仅定义了两个临时变量，故空间复杂度是O(1)。
*/
// C++ Solution 1:
