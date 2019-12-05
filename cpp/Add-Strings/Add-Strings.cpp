/// Source : https://leetcode.com/problems/add-two-numbers/description/
/// Author : bryce
/// Time   : 2019-12-5

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string res;
        while (i>=0 || j>=0)
        {
            int temp = 0;
            if (i<0)
                temp = num2[j]-'0'+carry;
            if (j<0)
                temp = num1[i]-'0'+carry;
            else
                temp = num1[i] - '0' + num2[j] -'0' + carry;
            carry = temp / 10;
            res.insert(res.begin(),temp%10+'0');
            i--;
            j--;
        }
        if (carry>0)
            res.insert(res.begin(),carry+'0');
        return res;
    }
};

{
    string num1 = "9";
    string num2 = "9";
    string  res;
    res = Solution().multiply(num1,num2);
    cout << res << endl;
    system ("pause");
    return 0;
}
