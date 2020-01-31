# 题目描述:  数字 1 的个数

给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
**示例 :**
```
输入: 13
输出: 6 
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
```
  
# 解题思路:
此题与剑指offer第四十三题一样

方法一：暴力遍历，对1\~n进行遍历，每一个数字都进行判断，从最高位一直判断到最低位，每次通过对10求余数判断整数的个位数字是不是1，大于10的除以10之后再判断。我们对每个数字都要做除法和求余运算以求出该数字中1出现的次数。如果输入数字n，n有O(logn)位，我们需要判断每一位是不是1，那么时间复杂度为O(n\*logn),空间复杂度O(1)。

方法二：对每一行使用一次二分查找，时间复杂度为O(m\*logn)

方法三：根据简单的例子寻找规律，从右上角开始寻找，时间复杂度为O(m+n)
 
# 时间复杂度：
  方法一：O(n\*logn)
  
  方法二： O(logn)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Number-Of-Digit-One.cpp):

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

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Number-Of-Digit-One/Number-Of-Digit-One.py)
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

  -  [剑指Offer-43题-1~n整数中1出现的次数](https://github.com/bryceustc/CodingInterviews/blob/master/NumberOf1/README.md)
