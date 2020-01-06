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

想要判断一个数的因子是否为2,3,5只需要判断对这个几个数进行取模看是否能够整除然后再除以这几个数，直到最后为1即是丑数，不是1则不为丑数。然后从1开始按照顺序判断每一个数是不是丑数。
 
# 时间复杂度：
  无法准确分析时间复杂度:至少O(n3)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Ugly-Number.cpp):

###  模拟法
```c++
class Solution {
public:
    bool isUgly(int num) {
        if (num<1)
            return false;
        while(num%5==0)
        {
            num/=5;
        }
        while(num%3==0)
        {
            num/=3;
        }
        while(num%2==0)
        {
            num/=2;
        }
        return num==1;
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



