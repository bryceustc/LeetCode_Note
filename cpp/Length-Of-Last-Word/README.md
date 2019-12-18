# 题目描述:  最后一个单词的长度

给定一个仅包含大小写字母和空格`` '  ' ``的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

**说明：** 一个单词是指由字母组成，但不包含任何空格的字符串。

**示例 :**
```
输入: "Hello World"
输出: 5
```

  
# 解题思路:
方法一：直接法，找到s最后一个非``' '``字符，然后以此坐标为边界，进行倒序搜索，找到第一个``' '``的字符，就返回``res``,否则``res+=1``

方法二：Python 3 首先用strip去掉字符串结尾的空格，之后用split对其切片并取最后一个元素，读取该元素长度即可
 
# 时间复杂度：
  O(n) 
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Length-Of-Last-Word.cpp):

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


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Length-Of-Last-Word/Length-Of-Last-Word.py)
###  方法一：直接法
```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res =0
        n=len(s)
        if n==0:
            return res
        m = n-1
        while m>=0 and s[m]==' ':
            m-=1
        for i in range (m,-1,-1):
            if s[i]==' ':
                break
            res+=1
        return res
```
### 方法二 ： split()用法
```python
Python 3 首先用strip去掉字符串结尾的空格，之后用split对其切片并取最后一个元素，读取该元素长度即可
```

# 参考

  -  [c++ trim()函数用法](https://www.cnblogs.com/carekee/articles/2094731.html)
  - [Python split()用法](https://www.runoob.com/python3/python3-string-split.html)
  - [Python strip()用法](https://www.runoob.com/python3/python3-string-strip.html)
   strip() 该方法只能删除开头或是结尾的字符，不能删除中间部分的字符
