# 题目描述:  字符串的排列

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

**示例 :**
```
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").

输入: s1= "ab" s2 = "eidboaoo"
输出: False
```
说明：
- 两个字符串的长度都在 [1, 10,000] 之间
- 输入的字符串只包含小写字母


# 解题思路:
套用滑动窗口模板

# 时间复杂度：
 O(n)
# 空间复杂度
O(n)
# 代码

### 滑动窗口算法
```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> needs, window;
        int n = s2.size();
        int left = 0, right = 0, valid = 0;
        for (char c: s1) needs[c]++;
        while(right<n)
        {
            char c = s2[right++];
            if (needs.count(c))
            {
                window[c]++;
                if (window[c]==needs[c])
                {
                    valid++;
                }
            }
            while(right-left>=s1.size())
            {
                if (valid==needs.size()) return true;
                char d = s2[left++];
                if (needs.count(d))
                {
                    if (window[d]==needs[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};
```
## 参考
  - [滑动窗口框架套路详解](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485141&idx=1&sn=0e4583ad935e76e9a3f6793792e60734&chksm=9bd7f8ddaca071cbb7570b2433290e5e2628d20473022a5517271de6d6e50783961bebc3dd3b&scene=126&sessionid=1587516905&key=90f15a20186b1d46c2992f11e82b01a0cda6178792cdef35f4436e8185c7cc6e973a629da69bafba62e0b6551c49abdf6c71bd261ba3c3acf9539e3ecf9390d5761103a4d3a3c3eb9f0c41aadad3a4c5&ascene=1&uin=MjE1ODMxOTYzOA%3D%3D&devicetype=Windows+10&version=62080079&lang=zh_CN&exportkey=A4FXMMlE%2Bef9sSA4mIuJSO0%3D&pass_ticket=ppDnFMJpc9c%2Bn6RJFcuQ6KqAmN5hl%2BcvIiSNRu3bA2J3Np0Zr%2Fv7M6xJCQYQC60l)
