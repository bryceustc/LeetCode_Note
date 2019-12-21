# 题目描述:  移动零

给定一个数组 ``nums``，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

**示例 :**
现有矩阵 matrix 如下：
```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```
**说明 :**

1. 必须在原数组上操作，不能拷贝额外的数组。

2. 尽量减少操作次数。

  
# 解题思路:
此题与剑指offer第21题类似

方法一：构建辅助数组，遍历，两次原数组，一次添加非零元素，一次添加0元素，时间复杂度为O(n)

方法二：利用插入排序的思想，外层循环遍历数组，找``0``元素所在的位置；内层循环找当前``0``元素所在位置之后的第一个非零元素。当当前位置的值为``0``时执行内层循环，假设当前位置``i``的值``num[i]=0``，内层循环的``j = i++``，即从当前0元素所在的下一个位置开始查找非零元素；当nums[j] != 0时，``nums[i] = nums[j]``，``nums[j]=0``，即交换``nums[i]``、``nums[j]``的值，并退出内层循环，执行外层循环。 时间复杂度(n<sup>2)

方法三：利用冒泡排序的思想，两层循环，内层从最后开始交换，时间复杂度为O(n<sup>2)
 
# 时间复杂度：
  方法一： On)
  
  方法二： O(n<sup>2)
  
  方法三： O(n<sup>2) 
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Move-Zeroes.cpp):

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

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Move-Zeroes/Move-Zeroes.py)
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




