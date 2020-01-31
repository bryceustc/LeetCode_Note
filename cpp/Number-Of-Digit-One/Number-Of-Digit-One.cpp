// Solution1：
class Solution {
public:
    int countDigitOne(int n) {
        int res =0;
        if (n<1)
            return res;
        for (int i=1;i<=n;i++)
        {
            res+=NumberOf1(i);
        }
        return res;
    }
    int NumberOf1(int n)
    {
        int num =0;
        while(n)
        {
            if (n%10==1)
            {
                num++;
            }
            n /= 10;
        }
        return num;
    }
};
// Solution 2:
class Solution {
public:
    int countDigitOne(int n) {
        long int res = 0;
        for (long int i=1;i<=n;i*=10)
        {
            long int a = n/i;
            long int b = n%i;
            res += (a+8)/10*i + (a%10==1)*(b+1);
        }
        return res;
    }
};
// Solution 3:
class Solution {
public:
    int countDigitOne(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string str = to_string(i);
            res += count(str.begin(), str.end(), '1');
        }
        return res;
    }
};
