####### Solution 1:
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        # 转置
        for i in range(n):
            for j in range(i,n):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
        #旋转
        for i in range(n):
            j = 0
            k = n-1
            while j<k:
                temp = matrix[i][j]
                matrix[i][j] = matrix[i][k]
                matrix[i][k] = temp
                j+=1
                k-=1
                
                
####### Solution 2:
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range (n):
            for j in range(i,n-1-i):
                temp = matrix[i][j]
                matrix[i][j] = matrix[n-1-j][i]
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
                matrix[j][n-1-i] = temp
