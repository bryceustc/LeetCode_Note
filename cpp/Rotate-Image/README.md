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
  观察矩阵，先转置后，在按中心竖线旋转，也就是翻转每一行，即可

# 时间复杂度：
  O(n<sup>2<\sup>)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Rotate-Image.cpp):

###转置旋转
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


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Rotate-Image/Rotate-Image.py)
### 转置旋转
```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1,n2 = len(num1),len(num2)
        res = [0 for i in range(n1+n2)]
        for i in range(n2-1,-1,-1):
            for j in range(n1-1,-1,-1):
                x,y = ord(num1[j])-ord('0'),ord(num2[i])-ord('0')
                temp = x*y + res[i+j+1]
                res[i+j+1] = temp % 10
                res[i+j] += temp // 10
        for i in range(0,n1+n2):
            if res[i] != 0:
                res = ''.join(str(x) for x in res[i:])
                return res
        return "0"
```
