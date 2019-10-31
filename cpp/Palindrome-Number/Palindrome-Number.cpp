/// Source : https://leetcode-cn.com/problems/palindrome-number/
/// Author : bryce
/// Time   : 2019-10-31
class Solution {
public:
    bool isPalindrome(int x) {
        int a = x;
        int n = 0;
        if (a < 0)
            return false;
        while (a != 0)
        {
            int m = a % 10;
            a/=10;
            if (n < INT_MAX/10 || (n == INT_MAX/10 && m <= 7))
                n = n * 10 + m;
            else 
                return false;
        }
       return x == n;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        int a = x;
        long long n = 0;
        if (a < 0)
            return false;
        while (a != 0)
        {
            int m = a % 10;
            a/=10;
            n = n * 10 + m;
        }
        return x == n;
    }
};
