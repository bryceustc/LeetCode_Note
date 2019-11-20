/// Source : https://leetcode-cn.com/problems/longest-palindromic-substring/
/// Author : bryce
/// Time   : 2019-10-26

/*
由于字符串长度小于1000，因此我们可以用 O(n^2)O的算法枚举所有可能的情况。
首先枚举回文串的中心 ii，然后分两种情况向两边扩展边界，直到遇到不同字符为止:

回文串长度是奇数，则依次判断 s[i−k]==s[i+k],k=1,2,3,…
回文串长度是偶数，则依次判断 s[i−k]==s[i+k−1],k=1,2,3,…
如果遇到不同字符，则我们就找到了以 i 为中心的回文串边界。

时间复杂度分析：一共两重循环，所以时间复杂度是 O(n^2)。


*/

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
