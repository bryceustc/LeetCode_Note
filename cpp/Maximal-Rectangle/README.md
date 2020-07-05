```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') dp[i][0] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j]=='1') {
                    dp[i][j] = dp[i][j-1] + 1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int w = INT_MAX;
                for (int k = i; k >=0; k--){
                    int h = i - k + 1;
                    w = min (w, dp[k][j]);
                    res = max(res, h*w);
                }
            }
        }
        return res;
    }
};
```
