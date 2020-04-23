# 题目描述:  无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

**示例 :**
```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
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
int lengthOfLongestSubstring(string s) 
{
    unordered_map<char, int> m;

    int left = 0, right = 0;
    int res = 0; // 记录结果
    while (right < s.size()) 
    {
        char c = s[right++];
        // 进行窗口内数据的一系列更新
        m[c]++;
        // 判断左侧窗口是否要收缩
        while (m[c] > 1)
        {
            char d = s[left++];
            // 进行窗口内数据的一系列更新
            m[d]--;
        }
        // 在这里更新答案
        res = max(res, right - left);
    }
    return res;
}
```
### 参考

- [滑动窗口总结](https://bryceustc.github.io/2020/04/22/%E5%8F%8C%E6%8C%87%E9%92%88%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E7%AE%97%E6%B3%95%E6%80%BB%E7%BB%93/#more)
