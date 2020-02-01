# 题目描述: 字符串中的第一个唯一字符

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:
```
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
```

**注意事项：**  您可以假定该字符串只包含小写字母。
  
# 解题思路:
  此题与剑指Offer<五十题>题目一一样，利用哈希表来求即可。

# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(n)
  
# 代码

## [C++](./First-Unique-Character-In-A-String.cpp):

### 哈希表
```c++
class Solution {
public:
    int firstUniqChar(string s) {
        int res = -1;
        int n = s.size();
        if (n==0) return res;
        unordered_map<char,int> m;
        for (int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        for (int i=0;i<n;i++) 
        {
            if (m[s[i]]==1)
            {
                return i;
            }
        }
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/First-Unique-Character-In-A-String/First-Unique-Character-In-A-String.py)
### 哈希表
```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        n = len(s)
        res = -1
        if n==0:
            return res
        count = collections.Counter(s)
        for index,ch in enumerate(s):
            if count[ch]==1:
                return index
        return res
```
# 参考
  -  [剑指offer-50题-第一个只出现一次的字符](https://github.com/bryceustc/CodingInterviews/blob/master/FirstNotRepeatingChar/README.md)
  -  [Python collections.Counter()方法](https://docs.python.org/zh-cn/3/library/collections.html)
  -  [Python collections.Counter()计数函数](https://blog.csdn.net/u014755493/article/details/69812244)

