class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()<2) return s;
        int n = s.size(), maxlen = 0, start = 0;
        for (int i = 0; i < n - 1; i++ )
        {
            findPalindrome(s, i, i, start, maxlen);
            findPalindrome(s, i, i+1, start, maxlen);
        }
        return s.substr(start, maxlen);
    }
    
    void findPalindrome(string s, int left, int right, int& start, int& maxlen){
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
