/// Source : https://leetcode-cn.com/problems/zigzag-conversion/submissions/
/// Author : bryce
/// Time   : 2019-10-26
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int n = s.length();
        int m = 2*numRows -2;
        if (numRows == 1) return s;
        for(int i = 0; i < numRows; i++ )
        {
            if(i == 0 || i == numRows -1)
            {
                for (int j = i; j <n; j+=m)
                {
                    res +=s[j];
                }
            }
            else
            {
                for (int j = i, k = 2 * numRows - i - 1 - 1; j < n || k < n; j+=m, k +=m)
                {
                    if (j <n)
                        res += s[j];
                    if (k <n)
                        res += s[k];
                }
            }
        }
        
        return res;
    }
};
