
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        //矩阵转置
        for (int i=0;i<n;i++)
        {
            for (int j=i;j<n;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
                //swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //按中心竖线旋转
        for (int i = 0;i<n;i++)
        {
            for(int j=0,k=n-1;j<k;j++,k--)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
            }
        }
    }
};
