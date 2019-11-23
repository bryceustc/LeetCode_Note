/// Source : https://leetcode-cn.com/problems/longest-valid-parentheses/
/// Author : bryce
/// Time   : 2019-11-23

/*
思路：碰到括号题首先可以考虑栈结构stack<int>
1.用栈维护当前待匹配的左括号的位置。同时用 start 记录一个新的可能合法的子串的起始位置。初始设为 0
2.遍历字符串s,遇到左括号，当前位置进栈。
3.遇到右括号，如果当前栈不空，则当前栈顶出栈(即左括号右括号匹配)。出栈后，如果栈为空，则用更新答案 i - start + 1；否则更新答案 i - stk.top()
4.遇到右括号且当前栈为空，则当前的 start 开始的子串不再可能为合法子串了，下一个合法子串的起始位置是 i + 1，更新 start = i + 1

举例：
对于“(()”

                  i=0：(；
                  i=1：(;
                  i=2：)；
                  因为，i=0是左括号(，入栈：
                            栈：(
                  因为i=1是左括号(，入栈：
                            栈：( (
                  因为i=2是右括号)，和栈顶元素(下面红色的那个)进行匹配：
                           栈：( (
                  所以栈顶元素出栈：
                           栈：(
                  因为i已经遍历到最后，且栈不为空，所以令最后一个i=2减去栈顶元素i=0，即：2 - 0 = 2
         对于“())”
                  因为，i=0是左括号(，入栈：
                           栈：(
                  因为i=1是右括号)，和栈顶元素(下面红色的那个)进行匹配：
                           栈：(
                  所以栈顶元素出栈：
                           栈：
                  此时栈为空，因此res = max( (i= 1) - (start = 0)+1, res ) = 2
                  因为，i=2是右括号)，且已经遍历到最后，且栈为空，所以start = 3 超出索引了


时间复杂度：每个位置遍历一次，所以是O(n)的时间复杂度
空间复杂度：栈需要O(n)的空间
*/
// C++ Solution 1:
class Solution {
public:
    int longestValidParentheses(string s) {
      int res = 0;
      int start = 0;
      int n = s.length();
      stack<int> stk;
      for (int i = 0; i < n; i++)
      {
        if(s[i]=='(')
          stk.push(i);
        else
        {
          if (!stk.empty())
          {
            stk.pop();//括号匹配，出栈
            if (stk.empty())
            {
              res = max(res,i-start+1);
            }
            else
            {
              res = max(res,i-stk.top());//不为空，则说明还有左括号，减去此时左括号的所在位置索引
            }
          }
          else  // 碰到右括号且栈为空，则其实位置需要更新+1
          {
            start = i + 1;
          }
        }
      }
      return res;
    }
};
