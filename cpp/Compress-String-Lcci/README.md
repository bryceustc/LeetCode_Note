# 题目描述:  字符串压缩

字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。


**示例 :**
```
 输入："aabcccccaaa"
 输出："a2b1c5a3"
```

# 解题思路:
1： 模拟法：

2：双指针:
# 时间复杂度：
  1: O(n)
  
  2: O(n)
# 空间复杂度
  1: O(1)
  
  2: O(1)
  
# 代码
### 模拟法
```c++
class Solution {
public:
    string compressString(string S) {
        if (S.empty()) return "";
        int n = S.size();
        string res;
        char s = S[0];  // 注意不能是string
        int count = 1;
        for (int i=1;i<n;i++)
        {
            if (S[i] == s)
            {
                count++;
                continue;
            }
            else
            {
                res += s;
                res += to_string(count);
                s = S[i];
                count = 1;
            }
        }
        res += s + to_string(count);
        return res.size()>=n?S:res;
    }
};
```
###  双指针
```c++
class Solution {
public:
    string compressString(string S) {
        if (S.empty()) return "";
        int n = S.size();
        string res;
        int i = 0, j = 0;
        while(i<n)
        {
            while (j<n && S[j]==S[i])
            {
                j++;
            }
            res += S[i];
            res += to_string(j-i);
            i = j;
        }
        return res.size()>=n?S:res;
    }
};
```
