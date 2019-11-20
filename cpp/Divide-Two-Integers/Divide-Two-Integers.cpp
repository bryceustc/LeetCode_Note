/// Source : https://leetcode-cn.com/problems/divide-two-integers/
/// Author : bryce
/// Time   : 2019-11-20

/*
思路：
1. 如果needle为空，直接返回0
2. 如果haystack为空或者子串长度大于母串长度则返回-1
3. 遍历haystack字符串，后对于每一个字符，都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，
  如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即i.
4. 跳出循环则返回-1
时间复杂度：
*/

// C++ Solution 1:(暴力解法：超出时间限制)
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = 0;
        long long a = divisor;
        long long b = dividend;
        if (divisor==0) 
            return INT_MAX;
        if (dividend == INT_MAX && divisor == 1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        while(abs(a)<=abs(b))
        {
            a+=divisor;
            res++;
        }
        if ((divisor>0 && dividend<0) || (divisor<0 && dividend>0))
            res *= -1;
        return int(res);
    }
};
