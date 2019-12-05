/// Source : https://leetcode-cn.com/problems/multiply-strings/
/// Author : bryce
/// Time   : 2019-12-4

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        string res(n1+n2,'0');
        for(int i=n2-1;i>=0;i--)
        {
            for(int j=n1-1;j>=0;j--)
            {
                int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
                res[i+j+1]=temp%10+'0';//当前位
                res[i+j]+=temp/10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }
        
        //去除首位'0'
        for(int i=0;i<n1+n2;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";
    }
};

int main()
{
    string num1 = "9";
    string num2 = "9";
    string  res;
    res = Solution().multiply(num1,num2);
    cout << res << endl;
    system ("pause");
    return 0;
}
