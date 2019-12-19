## Python Solution 1:
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        for i in range(m):
            for j in range(n):
               if matrix[i][j]==target:
                   return True
        return False

## Python Solution  2:
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        for i in range(m):
            start = 0
            end = n-1
            while end>=start:
                mid = start + (end-start)//2
                if matrix[i][mid] == target:
                    return True
                if matrix[i][mid]<target:
                    start=mid+1
                if matrix[i][mid]>target:
                    end=mid-1
        return False

## Python Solution  3:
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        i=0
        j=n-1
        while i<m and j>=0:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j]>target:
                j-=1
            else:
                i+=1
        return False

## Python Solution  4:
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        start = 0
        end = m*n-1
        while end>=start:
            mid = start + (end-start)//2
            if matrix[mid//n][mid%n] == target:
                return True
            if matrix[mid//n][mid%n]<target:
                start=mid+1
            if matrix[mid//n][mid%n]>target:
                end=mid-1
        return False

## Python Solution  5:
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        i=m-1
        j=0
        while i>=0 and j<n:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j]>target:
                i-=1
            else:
                j+=1
        return False
