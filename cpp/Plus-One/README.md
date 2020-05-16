# 题目描述:  加一

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头.


**示例 :**
```
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
```

# 解题思路:
巧妙数学解法：在原地操作，最后一位加一要么进位，要么不进位，就利用这点来做一个循环的退出条件
# 时间复杂度：
O(n) 
# 空间复杂度
O(1)
  
# 代码
### 数学解法
```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i=n-1;i>=0;--i)
        {
            digits[i]++;
            digits[i]%=10;
            if (digits[i]!=0) return digits;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};
```
