# 题目描述:  快乐数

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。


**示例 :**
```
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```
  
# 解题思路:
方法：使用“快慢指针”思想找出循环：“快指针”每次走两步，“慢指针”每次走一步，当二者相等时，即为一个循环周期。此时，判断是不是因为1引起的循环，是的话就是快乐数，否则不是快乐数。

注意：此题不建议用集合记录每次的计算结果来判断是否进入循环，因为这个集合可能大到无法存储；另外，也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃。不要因为这个题目给出的整数是int型而投机取巧。
 
# 时间复杂度：
  O(log(n))
# 空间复杂度
  O(1)
  
# 代码

###  快慢指针法
```c++
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = bitSuqareSum(fast);
        while(slow!=fast)
        {
            slow = bitSuqareSum(slow);
            fast = bitSuqareSum(fast);
            fast = bitSuqareSum(fast);
        }
        return slow==1;
    }

    int bitSuqareSum(int n)
    {
        int res = 0;
        while(n)
        {
            int bit = n%10;
            res += bit*bit;
            n/=10;
        }
        return res;
    }
};
```
# 参考

  -  [题解](https://leetcode-cn.com/problems/happy-number/solution/kuai-le-de-zhi-shi-dian-zeng-jia-liao-by-sweetiee/)
