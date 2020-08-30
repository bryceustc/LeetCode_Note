###题目描述： 重复的子字符串

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

i为子串的长度,对于任意的 i∈[n′,n)，有 s[i]=s[i−n′]

```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i * 2 <= n; i++) {
            if (n % i == 0) {
                bool flag = true;
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j-i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};
```
当 s 没有循环节时：

如果 s 中没有循环节，那么 ss 中必然有且只有两个 s，此时从 ss[1] 处开始寻找 s ，必然只能找到第二个，所以此时返回值为 s.size()。


当 s 有循环节时：

当 s 中有循环节时，设循环节为 r，其长度为 l，那么 ss 中必然有 s.size()/l + 1 个 s。
因为去掉了第一个 S 的第一个字符 (代码中，(s+s).find(s, 1)， 是从 ss[1] 处开始 find )
所以此时必回找到第二个 s 的起点。

```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};
```
