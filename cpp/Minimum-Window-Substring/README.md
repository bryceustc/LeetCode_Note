# 题目描述:  最小覆盖子串

给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

**示例 :**
```
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
```
说明：

- 如果 S 中不存这样的子串，则返回空字符串 ""。
- 如果 S 中存在这样的子串，我们保证它是唯一的答案。

# 解题思路:
套用滑动窗口模板

# 时间复杂度：
 O(n)
# 空间复杂度
O(n)
# 代码

### 滑动窗口算法
```c++
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    int n = s.size();
    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = INT_MAX;
    while (right < n) 
    {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        if (need.count(c)) 
        {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        // 判断左侧窗口是否要收缩
        while (valid == need.size())
        {
            // 在这里更新最小覆盖子串
            if (right - left < len)
            {
                start = left;
                len = right - left;
            }
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d))
            {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    // 返回最小覆盖子串
    return len == INT_MAX ? "" : s.substr(start, len);
}
```
## 参考
  - [滑动窗口框架套路详解](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485141&idx=1&sn=0e4583ad935e76e9a3f6793792e60734&chksm=9bd7f8ddaca071cbb7570b2433290e5e2628d20473022a5517271de6d6e50783961bebc3dd3b&scene=126&sessionid=1587516905&key=90f15a20186b1d46c2992f11e82b01a0cda6178792cdef35f4436e8185c7cc6e973a629da69bafba62e0b6551c49abdf6c71bd261ba3c3acf9539e3ecf9390d5761103a4d3a3c3eb9f0c41aadad3a4c5&ascene=1&uin=MjE1ODMxOTYzOA%3D%3D&devicetype=Windows+10&version=62080079&lang=zh_CN&exportkey=A4FXMMlE%2Bef9sSA4mIuJSO0%3D&pass_ticket=ppDnFMJpc9c%2Bn6RJFcuQ6KqAmN5hl%2BcvIiSNRu3bA2J3Np0Zr%2Fv7M6xJCQYQC60l)
