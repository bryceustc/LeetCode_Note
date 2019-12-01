/// Source : https://leetcode-cn.com/problems/count-and-say/
/// Author : bryce
/// Time   : 2019-11-29

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n==0) return "";
        string res = "1";
        while(--n)
        {
           string temp = "";
           for (int i=0;i<res.size();i++)
           {
              int cnt = 1;
              while(res[i+1]==res[i] && i+1<res.size())
              {
                 cnt++;
                 i++;
              }
              temp += to_string(cnt) + res[i];
           }
           res = temp;
        }
        return res;
    }
};

int main()
{
    int n = 4;
    cout << Solution().countAndSay(n)<< endl;
    system("pause");
    return 0;
}
