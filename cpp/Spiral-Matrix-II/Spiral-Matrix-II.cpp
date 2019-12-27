// c++ Solution 1:

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int>(n,0));  // 初始化为n*n的矩阵
        vector<int> out;
        int m = pow(n,2);
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        for (int i=m;i>0;i--)
        {
            out.push_back(i);
        }
        while(true)  // 注意换成while(nums<=m)会节省时间
        {
            for(int i=l;i<=r;i++)
            {
                res[u][i]=out.back();
                out.pop_back();
            }
            if (++u>d) break;
            for (int i=u;i<=d;i++)
            {
                res[i][r] = out.back();
                out.pop_back();
            }
            if (--r<l) break;
            for (int i=r;i>=l;i--) 
            {
                res[d][i] = out.back();
                out.pop_back();    
            }
            if (--d<u) break;
            for (int i=d;i>=u;i--) 
            {
                res[i][l] = out.back();
                out.pop_back();
            }
            if (++l>r) break;
        }
        return res;
    }
};
// 改进版
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int>(n,0));
        int m = pow(n,2);
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        int num = 1;
        while(num<=m)
        {
            for(int i=l;i<=r;i++)
            {
                res[u][i]=num++;
            }
            ++u;
            for (int i=u;i<=d;i++)
            {
                res[i][r] = num++;
            }
            --r;
            for (int i=r;i>=l;i--) 
            {
                res[d][i] = num++;
            }
            --d;
            for (int i=d;i>=u;i--) 
            {
                res[i][l] = num++;
            }
            ++l;
        }
        return res;
    }
};
