/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/// Author : bryce
/// Time   : 2019-10-10

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Sliding Window
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};

        int l = 0, r = 0; // sliding window: s[l...r]
        int res = 0;

        while(r < s.size()){
            if( freq[s[r]] == 0 )
            {
               freq[s[r]] ++;
               r++;
             }
            else
            {
               freq[s[l]] --;
               l++;
            }

            res = max(res, r - l);
        }
        return res;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j ++ )
        {
            hash[s[j]] ++ ;
            while (hash[s[j]] > 1) hash[s[i ++ ]] -- ;
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0

    return 0;
}
