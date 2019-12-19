# 题目描述:  搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

  - 每行中的整数从左到右按升序排列。
  - 每行的第一个整数大于前一行的最后一个整数。

**示例 1:**
```
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
```

**示例 2:**
```
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
```

  
# 解题思路:
方法一：直接暴力遍历二维数组所有元素，时间复杂度为O(m\*n)

方法二：对每一行使用一次二分查找，时间复杂度为O(m\*logn)

方法三：根据简单的例子寻找规律，从右上角开始寻找，时间复杂度为O()
 
# 时间复杂度：
  方法一： O(m\*n)
  
  方法二： O(m\*logn)
  
  方法三： O() 
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Search-A-2D-Matrix.cpp):

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

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Search-A-2D-Matrix/Search-A-2D-Matrix.py)
###  方法一：直接法
```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = 0
        n = len(s)
        if n==0:
            return res
        m = n - 1
        while m>=0 and s[m]==' ':
            m -=1
        for i in range (m,-1,-1):
            if s[i]==' ':
                break
            res +=1
        return res
```
### 方法二 ： strip()+split()用法
```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = 0
        s = s.strip(' ')
        s = s.split(' ')
        res = len(s[-1])
        return res
```

# 参考

  -  [c++ trim()函数用法](https://www.cnblogs.com/carekee/articles/2094731.html)

