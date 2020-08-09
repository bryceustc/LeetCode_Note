### 题目描述

93. 复原IP地址

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。


示例1：
```
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
```

暴力解法：
```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n  = s.size();
        string a, b,c,d;
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < i+4; ++j) {
                for (int k = j+1; k < j+4; ++k) {
                    if (i < n && j < n && k <n) {
                        a = s.substr(0, i+1);
                        b = s.substr(i+1, j-i);
                        c = s.substr(j+1, k-j);
                        d = s.substr(k+1, n- k);
                        // cout << a  << "." << b  << "."<< c  << "."<< d <<endl;
                        if (helper(a) && helper(b) && helper(c) && helper(d)) {
                            string out = a + "." + b + "." + c + "." + d;
                            res.push_back(out);
                        }
                    }
                }
            }
        }
        return res;
    }

    bool helper(string s) {
        if  (s.empty()  || s.size() == 0 || s.size() > 3 || (s[0] == '0' && s.size() > 1) || stoi(s) > 255 ) {
            return false;
        }
        return true;
    }
};
```
