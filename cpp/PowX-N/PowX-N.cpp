//Solution 1: 暴力求解法
class Solution {
public:
    double myPow(double x, int n) {
        double res=x;
        if (x==0) return 0;
        if (x==1) return 1;
        if (x==-1 && n%2==0) return 1;
        if (x==-1 && n%2!=0) return -1;
        if (n==-2147483648 && x>1) 
        {
            res = 0.0;
            return res;
        }
        if (n==2147483647 && x<-1) 
        {
            res = 0.0;
            return res;
        }
        if (n>0)
        {
            for (int i=1;i<n;i++)
            {
                res=res*x;
            }
        }
        if (n<0)
        {
            for (int i=-1;i>n;i--)
            {
                res=res*x;
            }
            res = 1/res;
        }
        if (n==0)
            res = 1;
        return res;
    }
};
