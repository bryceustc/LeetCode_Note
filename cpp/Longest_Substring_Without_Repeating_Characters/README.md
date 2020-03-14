# 题目描述:  无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
**示例 :**
```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

# 解题思路:
  滑动窗口+哈希表

# 时间复杂度：
O(n)
# 空间复杂度
 O(n)
  
# 代码

### 滑动窗口
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n==0) return 0;
        int res = 0;
        int left = 0;
        unordered_set<char> m;
        for (int i=0;i<n;i++)
        {
            while (m.count(s[i])!=0)
            {
                m.erase(s[left]);
                left++;
            }
            res = max(res, i-left+1);
            m.insert(s[i]);
        }
        return res;
    }
};
```
