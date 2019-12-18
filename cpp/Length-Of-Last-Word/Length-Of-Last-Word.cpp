// C++ Solution 1:
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res  = 0;
         if (s.empty()) return res;
        int n = s.size();
        int m=n-1;
        while(m>=0 && s[m]=='  ')
        {
            m--;
        }
        for (int i=m;i>=0;i--)
        {
            if (s[i]=='  ') break;
            res+=1;
        }
        return res;
    }
};
