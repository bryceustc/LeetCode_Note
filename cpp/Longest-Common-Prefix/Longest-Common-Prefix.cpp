  
/// Source : https://leetcode-cn.com/problems/longest-common-prefix/
/// Author : bryce
/// Time   : 2019-11-05

//C++ Solution 1:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int i = 0,b = 0;
        if (n == 0) return "";
        string res = "";
        int min_length = strs[0].size();
        for (i = 0; i < n; i++)
        {
            int m = strs[i].size();
            min_length = min(min_length,m);
            if (min_length >= m) b = i;
        }
        if (min_length==0) return "";
        res = strs[b];
        for (int l = 0; l < n; l++)
        {
            for(int j = 0; j < min_length;j++)
            {
                if (res[j] != strs[l][j])
                res = res.substr(0,j);           
            }
        }
        return res;
    }
};

// C++ Solution 2:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int min_length = strs[0].length();
        for (int i = 1; i < strs.size(); i++)
            min_length = min(min_length, int(strs[i].length()));

        for (int s = 1; s <= min_length; s++) {
            char c = strs[0][s - 1];
            for (int i = 1; i < strs.size(); i++)
                if (strs[i][s - 1] != c)
                    return strs[0].substr(0, s - 1);
        }
        return strs[0].substr(0, min_length);
    }
};
