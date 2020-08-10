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
DFS
```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n <4 || n > 12) return res;
        dfs(s,0);
        return res;
    }

    void dfs(string s, int start) {
        if (start == s.size() && temp.size() == 4) {  //temp中有4段且s结束
            string out;
            for (int i = 0; i < 4; i++) {
                if (i==3) {
                    out += temp[i];
                } else {
                    out += temp[i] + ".";
                }
            }
            res.push_back(out);  //res中保存一种可行方案
            return;
        } else if (start < s.size() && temp.size() == 4) {  //s有字符没用完
            return;
        }
        for (int len = 1; len <=3; len++) {   //temp中每一个string只能存长度1~3的字符串
            if (start  + len - 1>= s.size()) {   //超过了s的索引
                return;
            }
            if (s[start] == '0' && len > 1 ) {  //0x,00x非法
                return;
            }
            string str  = s.substr(start, len);  //切割字符串
            if (len ==3 && atoi(str.c_str()) > 255) {  //不能大于255
                return;
            }
            temp.push_back(str);
            dfs(s, start+len);
            temp.pop_back();
        }
    }
    private:
        vector<string> res;
        vector<string> temp;
};
```
