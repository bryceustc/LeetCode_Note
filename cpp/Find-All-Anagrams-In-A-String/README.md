# 题目描述:  找到字符串中所有字母异位词

给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

- 字母异位词指字母相同，但排列不同的字符串。
- 不考虑答案输出的顺序。 

**示例 :**
```
输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
```

# 解题思路:
  滑动窗口+哈希表，碰到子串问题，首先考虑滑动窗口

# 时间复杂度：
O(n)
# 空间复杂度
 O(n)
  
# 代码

### 滑动窗口
```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char,int> needs,windows;
        int left = 0, right = 0, valid = 0, n = s.size();
        for (char c: p) needs[c]++;
        while(right<n)
        {
            char c = s[right++];
            if (needs.count(c))
            {
                windows[c]++;
                if (windows[c]==needs[c])
                {
                    valid++;
                }
            }
            while(right-left==p.size())
            {
                if (valid==needs.size())
                {
                    res.push_back(left);
                }
                char d = s[left];
                if (needs.count(d))
                {
                    if(windows[d]==needs[d])
                        valid--;
                    windows[d]--;
                }
                left++;
            }
        }
        return res;
    }
};
```
### 参考

- [滑动窗口总结](https://bryceustc.github.io/2020/04/22/%E5%8F%8C%E6%8C%87%E9%92%88%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E7%AE%97%E6%B3%95%E6%80%BB%E7%BB%93/#more)
