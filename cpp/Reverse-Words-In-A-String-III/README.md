# 题目描述:  反转字符串中的单词 III

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

**示例 1:**
```
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
```
在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
  
# 解题思路:
  原地修改
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(1)
  
# 代码
```c++
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        int n = s.size();
        int start = 0;
        for (int i = 0; i < n+1; i++) {
            if (s[i] == ' ' || s[i] == '\0') {
                int end = i - 1;
                while (start < end) {
                    swap(s[start++], s[end--]);
                }
                start = i + 1;
            }
        }
        return s;
    }
};
```
