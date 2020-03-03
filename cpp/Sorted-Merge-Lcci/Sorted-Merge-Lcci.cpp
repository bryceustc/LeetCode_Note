class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m-1;
        int j = n-1;
        int index =  m+n-1;
        while (i>=0 && j>=0)
        {
            if(A[i]>=B[j])
            {
                A[index--] = A[i--];
            }
            else
            {
                A[index--] = B[j--];
            }
        }
        // 下面这个while没必要写，这时候index 和i是相等的。
        // while (i>=0)  A[index--] = A[i--];
        while (j>=0)  A[index--] = B[j--];
    }
};
