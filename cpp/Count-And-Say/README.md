# 题目描述: 报数

报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

```
1.     1
2.     11
3.     21
4.     1211
5.     111221
```
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

示例 1:
```
输入: 1
输出: "1"
```

示例 2:
```
输入: 4
输出: "1211"
```
  
# 解题思路:
  
  这道计数和读法问题还是第一次遇到，看似挺复杂，其实仔细一看，算法很简单，就是对于前一个数，找出相同元素的个数，把个数和该元素存到新的 string 里。

# 时间复杂度：
  O(n^3)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Count-And-Say.cpp):
### 直接法：
```c++
class Solution {
public:
    string countAndSay(int n) {
        if (n==0) return "";
        string res = "1";
        while(--n)
        {
           string temp = "";
           for (int i=0;i<res.size();i++)
           {
              int cnt = 1;
              while(res[i+1]==res[i] && i+1<res.size())
              {
                 cnt++;
                 i++;
              }
              temp += to_string(cnt) + res[i];
           }
           res = temp;
        }
        return res;
    }
};
```



## [Python:](LeetCode_Note/python/Count-And-Say/Count-And-Say.py)
### 直接法：
```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if n==0:
            return 0
        start = 0
        end = n
        while end > start:
            mid = start + (end-start)//2
            if nums[mid]<target:
                start=mid+1
            else:
                end = mid
        return start
```

### 利用python中的groupby
```python
from itertools import groupby
class Solution:
    def countAndSay(self, n: int, res='1') -> str:
        return res if n == 1 else self.countAndSay(n-1, ''.join([str(len(list(gen)))+val for val, gen in groupby(res)])

```
