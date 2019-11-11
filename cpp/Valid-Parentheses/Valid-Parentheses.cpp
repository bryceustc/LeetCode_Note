  
/// Source : https://leetcode-cn.com/problems/valid-parentheses/
/// Author : bryce
/// Time   : 2019-11-11

/*
栈结构
使用数据栈结构：
1.遇到左括号，就进行压栈
2.遇到右括号，如果此时栈为空，则直接返回false，如果不为空，就取出栈顶元素判断是否和当前括号匹配，若不匹配就返回false，否则匹配弹出栈顶
3.最后判断栈是否为空，若为空则合法，否则不合法
*/
class Solution {
public:
    bool isValid(string s) {
      int n = s.size();
      stack <char> stk;
      if (n % 2 != 0) return false;  //判断元素个数是否为奇数，奇数直接返回false
      for (int i = 0; i < n; i++)
      {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
          stk.push(s[i]);
        else
        {
          if (stk.empty()) return false;
          if (s[i] == ')' && stk.top() != '(') return false;
          if (s[i] == ']' && stk.top() != '[') return false;
          if (s[i] == '}' && stk.top() != '{') return false;
          stk.pop();   // pop 元素出栈
        }
      }
      return (stk.empty());
    }
};
