# 题目描述:  螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。


**示例 1:**
```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
```

**示例 2:**
```
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
```

  
# 解题思路:
  1. 首先设定上下左右边界

  2. 其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
  
  3. 判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
  
  4. 若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
  
  5. 不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
# 时间复杂度：
  O(n) 其中 n 是输入矩阵所有元素的个数。因为我们将矩阵中的每个元素都添加进答案里。
# 空间复杂度
  O(n) 需要矩阵 ``res`` 存储信息。
  
# 代码

## [C++](./Spiral-Matrix.cpp):

### 按层模拟
```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int u = 0;
        int d = m-1;
        int l = 0;
        int r = n-1;
        while(true)
        {
          for (int i=l;i<=r;i++) res.push_back(matrix[u][i]);//向右移动至最右
          if (++u > d) break;//重新定义上边界
          for (int i=u;i<=d;i++) res.push_back(matrix[i][r]);//向下
          if (--r < l) break;//重新定义右边界
          for (int i=r;i>=l;i--) res.push_back(matrix[d][i]);//向左
          if (--d < u) break;//重新定义下边界
          for (int i=d;i>=u;i--) res.push_back(matrix[i][l]);//向上
          if (++l > r) break;//重新定义左边界
        }
        return res;
    }
};
```



## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Spiral-Matrix/Spiral-Matrix.py)
### 按层模拟
```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        m = len(matrix)
        if m==0:
            return res
        n = len(matrix[0])
        u = 0
        d = m-1
        l = 0
        r = n-1
        while(True):
            for i in range(l,r+1):
                res.append(matrix[u][i])
            u+=1
            if u>d: break
            for i in range(u,d+1):
                res.append(matrix[i][r])
            r-=1
            if r<l:break
            for i in range(r,l-1,-1):
                res.append(matrix[d][i])
            d-=1
            if d<u:break
            for i in range(d,u-1,-1):
                res.append(matrix[i][l])
            l+=1
            if l>r:break
        return res
```
