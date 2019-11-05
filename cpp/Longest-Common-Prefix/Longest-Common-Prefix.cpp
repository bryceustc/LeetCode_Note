  
/// Source : https://leetcode-cn.com/problems/longest-common-prefix/
/// Author : bryce
/// Time   : 2019-11-05
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int i = 0,b = 0;
        if (n == 0) return "";
        string res = "";
        int a = strs[0].size();
        for (i = 0; i < n; i++)
        {
            int m = strs[i].size();
            a = min(a,m);
            if (a >= m) b = i;
        }
        if (a==0) return "";
        res = strs[b];
        for (int l = 0; l < n; l++)
        {
            for(int j = 0; j < a;j++)
            {
                if (res[j] != strs[l][j])
                res = res.substr(0,j);           
            }
        }
        return res;
    }
};
