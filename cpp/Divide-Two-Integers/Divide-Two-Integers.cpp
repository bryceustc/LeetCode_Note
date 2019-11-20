/// Source : https://leetcode-cn.com/problems/divide-two-integers/
/// Author : bryce
/// Time   : 2019-11-20

/*
思路：
1. x表示除数,y表示被除数,如果x==0,返回INT_MAX,如果y=INT_MIN且x=-1,返回INT_MAX, 剩余情况根据x和y的符号判断最终答案的符号,
2. 将x和y都取绝对值，假设y每次可以减掉最大的数为temp= 2^n*x,则可以根据二进制很容易的证明最多只需要O(logy)次这样的减法
3. 所以每次可以左移一位的temp增加一倍,答案为2^n

时间复杂度：
倍增找temp需要O(logy)的时间，共需要O(logy)次这样的减法，故总时间复杂度为 O((logy)^2)
*/

// C++ Solution 1:(暴力解法：超出时间限制,一直做减法，时间复杂度为O(y))
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = 0;
        long long a = divisor;
        long long b = dividend;
        if (divisor==0) 
            return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        a = abs(a);
        b = abs(b);
        while(a<=b)
        {
            b-=a;
            res++;
        }
        if ((divisor>0 && dividend<0) || (divisor<0 && dividend>0))
            res *= -1;
        return int(res);
    }
};

// C++ Solution 2:(利用位运算)
class Solution {
public:
    int divide(int dividend, int divisor) {
      long res = 0;
      long x = divisor;
      long y = dividend;
      if (x==0) return INT_MAX;
      if (y==INT_MIN && x == -1) return INT_MAX;
      x = abs(x);
      y = abs(y);
      while(y>=x)
      {
        long temp = x;
        long n = 1;
        while(y > temp<<1)//左移一位相当于*2
        {
          temp <<=1;
          n<<=1;
        }
        res+=n;
        y-=temp;
      }
      if ((divisor > 0 && dividend < 0)||(divisor < 0 && dividend > 0))
        res *= -1;
      return res;
    }
};
