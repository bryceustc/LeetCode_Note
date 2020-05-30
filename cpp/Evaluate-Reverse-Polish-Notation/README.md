# 题目描述:  逆波兰表达式求值

根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

**示例 1:**
```
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
```
**示例 2:**
```
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
```
**示例 3:**
```
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```
  
# 解题思路:
这是栈的一个典型应用，表达式求值。

利用栈暴力模拟
 
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

###  方法一： 直接法，方法比较啰嗦冗余。
```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        int n = tokens.size();
        stack<string> s;
        for (int i = 0; i < n; i++) {
            if (tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") {
                s.push(tokens[i]);
            }
            else
            {
                string sa = s.top();
                s.pop();
                string sb = s.top();
                s.pop();
                int a = atoi(sa);
                int b = atoi(sb);
                if (tokens[i]=="+")
                {
                    int c = b+a;
                    string sc = to_string(c);
                    s.push(sc);
                }
                else if (tokens[i]=="-"){
                    int c = b-a;
                    string sc = to_string(c);
                    s.push(sc);
                }
                else if (tokens[i]=="*"){
                    int c = b*a;
                    string sc = to_string(c);
                    s.push(sc);
                }
                else if (tokens[i]=="/"){
                    int c = b/a;
                    string sc = to_string(c);
                    s.push(sc);
                }
            }
        }
        // while(!s.empty()){
        //     string tmp = s.top();

        // }
        string s1 = s.top();
        s.pop();
        res = atoi(s1);
        return res;
    }

    int atoi(const string& s){
        int n = s.size();
        int flag = 1;
        int i = 0;
        if (s[0]== '-')
        {
            flag = -1;
            i++;
        }
        else if (s[0]=='+'){
            i++;
        }
        int res = 0;
        for (;i<n; i++){
            char c = s[i];
            int tmp = c - '0';
            res = res * 10 + tmp;
        }
        res *= flag;
        return res;
    }
};
```
# 参考

  -  [C++ 学习笔记之——字符串和字符串流](https://segmentfault.com/a/1190000017271382)
