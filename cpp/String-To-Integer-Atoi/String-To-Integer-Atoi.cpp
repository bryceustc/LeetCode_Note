/// Source : https://leetcode-cn.com/problems/string-to-integer-atoi/
/// Author : bryce
/// Time   : 2019-10-30
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i = 0;
        int flag = 1;
        // 1. 检查空格和回车
        while (i < str.size() && (str[i] == ' ' || str[i] == '\t')) 
        { 
            i++; 
        }
        if (i >str.size()) 
            return 0;
        // 2. 检查符号
        if (str[i] == '-') 
        { 
            flag = -1;
            i++;
        }
        if (str[i] == '+') 
        { 
            if (flag == -1)
                return 0;
            else 
                i++;
        }
        // 3. 计算数字
        while (str[i]>='0' && str[i] <='9')
        {
            int r = str[i] - '0';
            if ((res > INT_MAX /10 || (res == INT_MAX /10 && r > 7)))
            {
                if (flag > 0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            res = res * 10 + r;
            i++;
        }
        
        res *= flag;
        return res;
    }
};
int main() {

    cout << Solution().myAtoi( "123" )<<endl;
    return 0;
}
