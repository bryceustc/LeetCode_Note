/// Source : https://leetcode-cn.com/problems/integer-to-roman/
/// Author : bryce
/// Time   : 2019-11-03
#include <iostream>
#include <string>
using namespace std;

//C++ Solution1：
class Solution {
public:
    string intToRoman(int num) {
        string res;
        string s1,s2,s3,s4;
        int a = num;
        if(a <= 3999 && a >=1)
        {
            int m = a % 10;//个位数
            if (m == 1)
                s1 = "I";
            if (m == 2)
                s1 = "II";
            if (m == 3)
                s1 = "III";
            if (m == 4)
                s1 = "IV";
            if (m == 5)
                s1 = "V";
            if (m == 6)
                s1 = "VII";
            if (m == 7)
                s1 = "VII";
            if (m == 8)
                s1 = "VIII";
            if (m == 9)
                s1 = "IX";
                
            int n = (a/10) % 10;//十位数
                //std::cout << n << endl;
            n *= 10;

            if (n == 10)
                s2 = "X";
                
            if (n == 20)
                s2 = "XX";
            if (n == 30)
                s2 = "XXX";
            if (n == 40)
                s2 = "XL";
            if (n == 50)
                s2 = "L";
            if (n == 60)
                s2 = "LX";
            if (n == 70)
                s2 = "LXX";
            if (n == 80)
                s2 = "LXXX";
            if (n == 90)
                s2 = "LX";

            int k = (a/100) % 10; //百位数
            k *= 100;
            if (k == 100)
                s3 = "C";
            if (k == 200)
                s3 = "CC";
            if (k == 300)
                s3 = "CCC";
            if (k == 400)
                s3 = "CD";
            if (k == 500)
                s3 = "D";
            if (k == 600)
                s3 = "DC";
            if (k == 700)
                s3 = "DCC";
            if (k == 800)
                s3 = "DCCC";
            if (k == 900)
                s3 = "CM";
                
            int i = a / 1000;
            i = i * 1000;
            if (i == 1000)
                s4 = "M";
            if (i == 2000)
                s4 = "MM";
            if (i == 3000)
                s4 = "MMMM";
            cout << s4 << endl;
            cout << s3 << endl;
            cout << s2 << endl;
            cout << s1 << endl;   
            res = s4 + s3 + s2 + s1;
            cout << res << endl;
        }
        return res;
    }
};
//可以利用字符串数组来用
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<string> v1{"", "M", "MM", "MMM"};
        vector<string> v2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> v3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> v4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        res = v1[num / 1000] + v2[(num / 100) % 10] + v3[(num/ 10) % 10] + v4[num % 10];
        return res;
    }
};


//更通用的一种解法
// C++ Solution2:
class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<int> val ={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); i++) //类似贪心
        {
            while (num >= val[i]) 
            {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};

int main() {

    cout << Solution().intToRoman(2000) << endl; // false
    return 0;
}
