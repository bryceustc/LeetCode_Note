/// Source : https://leetcode-cn.com/problems/longest-palindromic-substring/
/// Author : bryce
/// Time   : 2019-10-26

#include <iostream>
#include <string>
#include <cassert>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()<2) return s;
        int n = s.size(), maxlen = 0, start = 0;
        for (int i = 0; i < n - 1; i++ )
        {
            findPalindrome(s, i, i, start, maxlen);//奇数情况
            findPalindrome(s, i, i+1, start, maxlen);//偶数情况
        }
        return s.substr(start, maxlen);
    }
    
    void findPalindrome(string s, int left, int right, int& start, int& maxlen){//用&是通过引用访问实参 控制实参的
        while(left >=0 && s[left] == s[right]){
            left--;
            right++;
        }
        if (maxlen < right - left - 1){
            start = left + 1;
            maxlen = right - left - 1;
        }
    }
};

int main() {

    cout << Solution().longestPalindrome( "babad" )<<endl; 
    cout << Solution().longestPalindrome( "cbbd" )<<endl; 
    return 0;
}
