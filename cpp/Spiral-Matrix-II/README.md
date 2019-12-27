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
  O(n) 
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Spiral-Matrix-II.cpp):

###  方法一： 直接法
```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int>(n,0));
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
        while(true)
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


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Spiral-Matrix-II/Spiral-Matrix-II.py)
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
