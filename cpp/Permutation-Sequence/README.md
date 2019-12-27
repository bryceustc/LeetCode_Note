# 题目描述:  螺旋矩阵 II

给定一个正整数 `n`，生成一个包含 1 到 n<sup>2</sup>所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

**示例 :**
```
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

  
# 解题思路:
类似螺旋矩阵I的解法，初始化二维数组，初始化一个一维数组为1 到 n<sup>2</sup>，类似螺旋矩阵I,找出四个边界，循环，赋值，每赋一次值一维数组就弹出这个该元素。
 
# 时间复杂度：
  O(n<sup>2</sup>)  遍历矩阵所有元素
# 空间复杂度
  O(n<sup>2</sup>)  需要一个n\*n矩阵存储元素
  
# 代码

## [C++](./Permutation-Sequence.cpp):

###  方法一： 模拟法
```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int>(n,0));  // 初始化为n*n的矩阵
        vector<int> out;
        int m = pow(n,2);
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        for (int i=m;i>0;i--)
        {
            out.push_back(i);
        }
        while(true)  // 注意换成while(nums<=m)会节省时间
        {
            for(int i=l;i<=r;i++)
            {
                res[u][i]=out.back();
                out.pop_back();
            }
            if (++u>d) break;
            for (int i=u;i<=d;i++)
            {
                res[i][r] = out.back();
                out.pop_back();
            }
            if (--r<l) break;
            for (int i=r;i>=l;i--) 
            {
                res[d][i] = out.back();
                out.pop_back();    
            }
            if (--d<u) break;
            for (int i=d;i>=u;i--) 
            {
                res[i][l] = out.back();
                out.pop_back();
            }
            if (++l>r) break;
        }
        return res;
    }
};
```

###  模拟法改进版
```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int>(n,0));
        int m = pow(n,2);
        int u = 0;
        int d = n-1;
        int l = 0;
        int r = n-1;
        int num = 1;
        while(num<=m)
        {
            for(int i=l;i<=r;i++)
            {
                res[u][i]=num++;
            }
            ++u;
            for (int i=u;i<=d;i++)
            {
                res[i][r] = num++;
            }
            --r;
            for (int i=r;i>=l;i--) 
            {
                res[d][i] = num++;
            }
            --d;
            for (int i=d;i>=u;i--) 
            {
                res[i][l] = num++;
            }
            ++l;
        }
        return res;
    }
};
```




## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Permutation-Sequence/Permutation-Sequence.py)
###  方法一：模拟法
```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0]* n for _ in range(n)]    ##python初始化二维数组
        out = [i for i in range(n*n,0,-1)]
        u = 0
        d = n-1
        l = 0
        r = n-1
        while True:  ## 可以改为while num<=pow(n,2): 更节省时间
            for i in range(l,r+1,1):
                res[u][i] = out[-1]
                #del out[-1]
                out.pop()
            u+=1
            if u>d:break
            for i in range(u,d+1,1):
                res[i][r] = out[-1]
                del out[-1]
            r-=1
            if r<l:break
            for i in range(r,l-1,-1):
                res[d][i] = out[-1]
                del out[-1]
            d-=1
            if d<u:break
            for i in range(d,u-1,-1):
                res[i][l]=out[-1]
                del out[-1]
            l+=1
            if l>r:break
        return res
```

###  方法一：模拟法改进版
```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0]* n for _ in range(n)]    ##python初始化二维数组
        # res = [[0 for _ in range(n)] for _ in range(n)]
        u = 0
        d = n-1
        l = 0
        r = n-1
        m = pow(n,2)
        num = 1
        while num<=m:
            for i in range(l,r+1,1):
                res[u][i] = num
                num+=1
            u+=1
            for i in range(u,d+1,1):
                res[i][r] = num
                num+=1
            r-=1
            for i in range(r,l-1,-1):
                res[d][i] = num
                num+=1
            d-=1
            for i in range(d,u-1,-1):
                res[i][l]=num
                num+=1
            l+=1
        return res
```


# 参考

  -  [螺旋矩阵](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Spiral-Matrix/README.md)
  -  [c++多维数组初始化](https://blog.csdn.net/ldkcumt/article/details/51396980)
  -  [python初始化二维数组](https://www.cnblogs.com/yeni/p/11590108.html)

