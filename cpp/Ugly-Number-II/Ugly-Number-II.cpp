class Solution {
public:
    bool isUgly(int num) {
        if (num<1)
            return false;
        while(num%5==0)
        {
            num/=5;
        }
        while(num%3==0)
        {
            num/=3;
        }
        while(num%2==0)
        {
            num/=2;
        }
        return num==1;
    }
    int nthUglyNumber(int n) {
        int i = 0;
        int num = 0;
        while(i<n)
        {
            num++;
            if (isUgly(num))
            {
                i++;
            }
            
        }
        return num;
    }
};
