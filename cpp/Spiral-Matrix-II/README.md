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
方法一：直接法，找到s最后一个非``' '``字符，然后以此坐标为边界，进行倒序搜索，找到第一个``' '``的字符，就返回``res``,否则``res+=1``

方法二：Python 3 首先用strip去掉字符串结尾的空格，之后用split对其切片并取最后一个元素，读取该元素长度即可
 
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
    int lengthOfLastWord(string s) {
        int res  = 0;
         if (s.empty()) return res;
        int n = s.size();
        int m=n-1;
        while(m>=0 && s[m]=='  ')
        {
            m--;
        }
        for (int i=m;i>=0;i--)
        {
            if (s[i]=='  ') break;
            res+=1;
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
