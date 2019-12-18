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

方法二：
 
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

###  方法二： 双指针
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts,ends;
        for (int i=0;i<n;i++)
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        for (int i=0,j=0;i<n;i++)
        {
            if (i==n-1||starts[i+1]>ends[i])
            {
                res.push_back({starts[j],ends[i]});
                j=i+1;
            }
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
### 方法二 ： 双指针
```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n=len(intervals)
        if n==0:
            return []
        res =[]
        starts=[]
        ends=[]
        for i in range(n):
            starts.append(intervals[i][0])
            ends.append(intervals[i][1])
        starts = sorted(starts)
        ends = sorted(ends)
        i=0
        j=0
        while i<n:
            if i==n-1 or starts[i+1]>ends[i]:
                res.append([starts[j],ends[i]])
                j=i+1
            i+=1
        return res
```

# 参考

  -  [c++ trim()函数用法](https://www.cnblogs.com/carekee/articles/2094731.html)
