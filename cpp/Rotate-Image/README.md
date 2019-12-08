# 题目描述:  旋转图像

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

**说明：**

你必须在**原地**旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

**示例 1:**
```
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

**示例 2:**
```
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```
  
# 解题思路:
  方法一：观察矩阵，先转置后，再按中心竖线旋转，也就是翻转每一行，即可
  
  方法二：观察矩阵变换坐标，如下图所示：
  
  ![guilv](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Rotate-Image/Images/guilv.JPG)
  
  然后发现限定条件。这里i的取值范围是 ``[0, n/2)``，j的取值范围是 ``[i, n-1-i)``，至于为什么i和j是这个取值范围，为啥i不用遍历 ``[n/2, n)``，若仔细观察这些位置之间的联系，不难发现，实际上j列的范围 ``[i, n-1-i)`` 顺时针翻转 90 度，正好就是i行的 ``[n/2, n)`` 的位置

# 时间复杂度：
  O(n<sup>2)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Rotate-Image.cpp):

### 方法一： 转置旋转
```c++
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
```

### 方法二：寻找坐标规律变换
```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0;i<n/2;i++)
        {
            for (int j=i;j<n-1-i;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Rotate-Image/Rotate-Image.py)
### 方法一： 转置旋转
```python
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
```

### 方法二：寻找坐标规律变换
```python
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
```
