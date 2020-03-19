# 题目描述:  最长回文串

给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

**示例 :**
```
输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
```
# 解题思路:
  哈希法
  
# 代码

###  利用哈希表哈希（不是最优）
```c++
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        int res = 0;
        int mid = 0;  // 中心点
        unordered_map<char,int> m;
        set<char> st;
        for (char c: s)
        {
            m[c]++;
            st.insert(c);
        }
        for (char c :st)
        {
            if ((m[c]&1)==0)
            {
                res+=m[c];
            }
            else
            {
                res += m[c]-1; //如果某字符为奇数个，则丢弃1个，其余的使用在回文串里
                mid = 1; //此时，标记回文串可以有中心点
            }
        }
        res += mid;
        return res;
    }
};
```
### 利用数组哈希(这道题目要保存的键是固定的，a-z,A-Z, 使用数组比map减少了判断和插入的时间，能用数组哈希就可能用数组哈希，数组效率更高一点)
```c++
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.empty()) return 0;
        int res = 0;
        int mid = 0;  // 中心点
        int char_map[128] = {0};
        for (char c: s)
        {
            char_map[c]++;  //利用整数的数组下标实现字符哈希,统计字符个数
        }
        for (int i=0;i<128;i++)
        {
            if ((char_map[i]&1)==0)  //如果某字符为偶数个，则均可以使用在回文串里
            {
                res+=char_map[i];  
            }
            else
            {
                res += char_map[i]-1; //如果某字符为奇数个，则丢弃1个，其余的使用在回文串里
                mid = 1; //此时，标记回文串可以有中心点
            }
        }
        res += mid; // 结果为偶数部分的最大长度+中心字符
        return res;
    }
};
```
