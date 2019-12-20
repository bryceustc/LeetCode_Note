# 题目描述:  寻找旋转排序数组中的最小值

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

**示例 1:**
```
输入: [3,4,5,1,2]
输出: 1
```

**示例 2:**
```
输入: [4,5,6,7,0,1,2]
输出: 0
```

  
# 解题思路:
此题与剑指offer第十一题相似

方法一：直接暴力遍历数组所有元素，寻找最小元素，时间复杂度为O(n)

方法二：使用二分查找，如果中间元素大于等于首元素，``start=mid+1``，时间复杂度为O(logn)

方法三：利用STL容器vector里边sort函数，时间复杂度为O(n)
 
# 时间复杂度：
  方法一： O(n)
  
  方法二： O(logn)
  
  方法三： O(n) 
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Find-Minimum-In-Rotated-Sorted-Array.cpp):

###  方法一： 直接暴力遍历法
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty()) return false;
            int m = matrix.size();
            int n = matrix[0].size();
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (matrix[i][j]==target)
                        return true;
                }
            }
            return false;        
    }
};
```

###  方法二： 遍历+一次二分查找法
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty()) return false;
            int m = matrix.size();
            int n = matrix[0].size();
            for (int i=0;i<m;i++)
            {
                int start = 0;
                int end = n-1;
                while(end>=start)
                {
                    int mid = start+(end-start)/2;
                    if (matrix[i][mid]==target)
                        return true;
                    else if (matrix[i][mid]<target)
                        start=mid+1;
                    else if (matrix[i][mid]>target)
                        end=mid-1;
                }
            }
            return false;        
    }
};
```
###  方法三： 二分查找法(将二维数组展成一维数组，因为条件2 ，矩阵数组有序)
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty()) return false;
            int m = matrix.size();
            int n = matrix[0].size();
            int start = 0;
            int end = m*n-1;
            while(end>=start)
            {
                int mid = start+(end-start)/2;
                if (matrix[mid/n][mid%n]==target)
                    return true;
                else if (matrix[mid/n][mid%n]<target)
                    start=mid+1;
                else if (matrix[mid/n][mid%n]>target)
                    end=mid-1;
            }
            return false;        
    }
};
```

###  方法四： 从右上角开始查找
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0)
        {
            if (matrix[i][j]==target)
                return true;
            if (matrix[i][j]>target)
                j--;  //左移
            else
                i++; // 下移
        }
        return false;
    }
};
```

###  方法五： 从左下角开始查找
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i=m-1,j=0;
        while(i>=0&& j<n)
        {
            if (matrix[i][j]==target)
                return true;
            if (matrix[i][j]>target)
                i--;  //上移
            else
                j++; // 右移
        }
        return false;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Find-Minimum-In-Rotated-Sorted-Array/Find-Minimum-In-Rotated-Sorted-Array.py)
###  方法一：暴力遍历法
```python
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
```
### 方法二 ：遍历+一次二分查找
```python
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
```

### 方法三 ：一次二分查找
```python
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
```

### 方法四 ：右上角查找
```python
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
```

### 方法五 ：左下角查找
```python
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
```

# 参考

  -  [旋转数组的最小数字](https://github.com/bryceustc/CodingInterviews/blob/master/MinNumberInRotatedArray/README.md)
  -  [二分查找算法](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/BinarySearch.md)


