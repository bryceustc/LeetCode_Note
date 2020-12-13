# 题目描述:  217. 存在重复元素

给定一个整数数组，判断是否存在重复元素。

如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

**示例 1:**
```
输入: [1,2,3,1]
输出: true

输入: [1,2,3,4]
输出: false
```

  
# 解题思路:
  哈希
# 时间复杂度：
  O(n) 
# 空间复杂度
  O(n)
  
# 代码

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int &num: nums) {
            if(s.count(num)) return true;
            s.insert(num);
        }
        return false;
    }
};
```
