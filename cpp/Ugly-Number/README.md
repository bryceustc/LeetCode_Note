# 题目描述:  丑数

编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 2, 3, 5 的**正整数**。

**示例1 :**
```
输入: 6
输出: true
解释: 6 = 2 × 3
```

**示例2 :**
```
输入: 8
输出: true
解释: 8 = 2 × 2 × 2
```

**示例3 :**
```
输入: 14
输出: false 
解释: 14 不是丑数，因为它包含了另外一个质因数 7。
```

**说明：**
  1. ``1``是丑数
  2. 输入不会超过 32 位有符号整数的范围: [−2<sup>31<\sup>,  2<sup>31<\sup> − 1]。

  
# 解题思路:
此题与剑指offer第四十五题类似

方法一：直接暴力遍历二维数组所有元素，时间复杂度为O(m\*n)

方法二：对每一行使用一次二分查找，时间复杂度为O(m\*logn)

方法三：根据简单的例子寻找规律，从右上角开始寻找，时间复杂度为O(m+n)
 
# 时间复杂度：
  方法一： O(m\*n)
  
  方法二： O(m\*logn)
  
  方法三： O(m+n) 
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Search-A-2D-Matrix-II.cpp):

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

###  方法三： 从右上角开始查找
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

###  方法四： 从左下角开始查找
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

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Search-A-2D-Matrix-II/Search-A-2D-Matrix-II.py)
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

### 方法三 ：右上角查找
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

### 方法四 ：左下角查找
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

  -  [二维数组中的查找](https://github.com/bryceustc/CodingInterviews/blob/master/FindInPartiallySortedMatrix/README.md)
  -  [搜索二维矩阵](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Search-A-2D-Matrix/README.md)



