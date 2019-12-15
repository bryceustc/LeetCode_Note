class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int u = 0;
        int d = m-1;
        int l = 0;
        int r = n-1;
        while(true)
        {
          for (int i=l;i<=r;i++) res.push_back(matrix[u][i]);//向右移动至最右
          if (++u > d) break;//重新定义上边界
          for (int i=u;i<=d;i++) res.push_back(matrix[i][r]);//向下
          if (--r < l) break;//重新定义右边界
          for (int i=r;i>=l;i--) res.push_back(matrix[d][i]);//向左
          if (--d < u) break;//重新定义下边界
          for (int i=d;i>=u;i--) res.push_back(matrix[i][l]);//向上
          if (++l > r) break;//重新定义左边界
        }
        return res;
    }
};
