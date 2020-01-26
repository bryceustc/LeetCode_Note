/// Source : https://leetcode-cn.com/problems/regular-expression-matching/
/// Author : bryce
/// Time   : 2019-11-1

// Solution 1:
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) 
            return s.empty();
        if (p[1]!='*')
        {
            if (s[0]==p[0] || p[0]=='.' && !s.empty())
                return isMatch(s.substr(1),p.substr(1));
            else
                return false;
        }
        else
        {
            if (s[0]==p[0] || p[0]=='.' && !s.empty())
                return (isMatch(s,p.substr(2)) || isMatch(s.substr(1),p));
            else
                return isMatch(s, p.substr(2));
        }
    }
};

// Solution2
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        s = " " + s;
        p = " " + p;
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (i > 0 && (s[i] == p[j] || p[j] == '.'))
                    f[i][j] = f[i][j] | f[i - 1][j - 1];
                if (p[j] == '*') {
                    if (j >= 2)
                        f[i][j] = f[i][j] | f[i][j - 2];
                    if (i > 0 && (s[i] == p[j - 1] || p[j - 1] == '.'))
                        f[i][j] = f[i][j] | f[i - 1][j];
                }
            }
        return f[n][m];
    }
};
