/// Source : https://leetcode-cn.com/problems/roman-to-integer/
/// Author : bryce
/// Time   : 2019-11-04
#include <iostream>
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

//C++ Solution 1: 利用哈希表查找
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();
        unordered_map<char, int> words;
        words['I'] = 1; words['V'] = 5;
        words['X'] = 10; words['L'] = 50; 
        words['C'] = 100; words['D'] = 500;
        words['M'] = 1000;
        for (int i = 0; i < n; i++) {
            int val = words[s[i]];
            if (i != n - 1 && words[s[i+1]] > words[s[i]])
            {
                res += words[s[i+1]] -words[s[i]];
                i++;
            }                   
            else 
                res += val;
        }
        return res;
    }
};
//C++ Solution 2: 
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();
        int flag[256] = {0};
        flag['I'] = 1; flag['V'] = 5;
        flag['X'] = 10; flag['L'] = 50;
        flag['C'] = 100; flag['D'] = 500;
        flag['M'] = 1000;
        for (int i = 0; i < n; i++) {
            int val = flag[s[i]];
            if (i != n - 1 && flag[s[i+1]] > flag[s[i]])
            {
                res += flag[s[i+1]] - flag[s[i]];
                i++;
            }                   
            else
            {
                res += val;
            }
                
        }
        return res;
    }
};

int main()
{
    cout << Solution().romanToInt("CDI") << endl;
    return 0;
}
