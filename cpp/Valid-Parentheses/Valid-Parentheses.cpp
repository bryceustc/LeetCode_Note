  
/// Source : https://leetcode-cn.com/problems/valid-parentheses/
/// Author : bryce
/// Time   : 2019-11-11

/*
LeetCode 中关于数字之类似的还有Two Sum ，3Sum ，3Sum Closest，解法的思路跟3Sum 基本没啥区别，就是多加了一层 for 循环，其他的都一样.
使还有一种解法是为了避免重复项，STL 中的 TreeSet，其特点是不能有重复，如果新加入的数在 TreeSet 中原本就存在的话，插入操作就会失败，这
样能很好的避免的重复项的存在。
*/
