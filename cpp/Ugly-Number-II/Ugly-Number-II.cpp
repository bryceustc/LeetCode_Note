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



// C++ Solution 2:
class Solution {
public:
    int nthUglyNumber(int n) {
        int res =0;
        if (n<7)
            return n;
        vector<int> dp(n,0);
        dp[0] = 1;
        int l_2 = 0;
        int l_3 = 0;
        int l_5 = 0;
        for (int i=1;i<n;i++)
        {
            dp[i] = My_min(dp[l_2]*2,dp[l_3]*3,dp[l_5]*5);
            if (dp[l_2]*2<=dp[i])
                l_2++;
            if (dp[l_3]*3<=dp[i])
                l_3++;
            if (dp[l_5]*5<=dp[i])
                l_5++;
        }
        return dp[n-1];
    }

    int My_min(int a, int b, int c)
    {
        int res = min(a,b);
        res = min(res,c);
        return res;
    }
};

// C++ Solution 3:
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long ,vector<long long>,greater<long>> min;
        min.push(1);
        long long res = 0;
        long long num = 0;
        vector<int> temp;
        for (int i=0;i<n;i++)
        {
            res = min.top();
            min.pop();
            while(!min.empty() && res == num)
            {
                res = min.top();
                min.pop();
            }
            num =res;
            min.push(res*2);
            min.push(res*3);
            min.push(res*5);
        }
        return res;
    }
};
