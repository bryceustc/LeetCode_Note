class Solution {
public:
    bool isNumber(string s) {
        bool num = false, numAfterE = true, decimal = false, hasE = false, sign = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) 
        {
            // 空格：当前位置是空格但下一位置不为空格并且之前出现过数字、自然底数、小数点、符号，如：1. 3,返回false
            if (s[i] == ' ') 
            {
                if (i < n - 1 && s[i + 1] != ' ' && (num || decimal || hasE || sign)) return false;
            } 
            // 符号：'+'和'-'要么出现在开头，要么出现在e之后，所以，'+'和'-'之前一位必须为'e'或者' ' 例：" +12"或"2e+2"
            else if (s[i] == '+' || s[i] == '-') 
            {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
                sign = true;
            } 
            // 数字：数字范围要在0~9之间
            else if (s[i] >= '0' && s[i] <= '9') 
            {
                num = true;
                numAfterE = true;
            } 
            // 小数点：小数点需在自然指数之后且只出现一次，否则无效。例："2e3.4" 无效
            else if (s[i] == '.') 
            {
                if (decimal || hasE) return false;
                decimal = true;
            } 
            // 自然底数：e需在数字之后且只能出现一次，否则无效，例 "e3"，无效
            else if (s[i] == 'e') 
            {
                if (hasE || !num) return false;
                hasE = true;
                numAfterE = false;
            } 
            // 其他字符出现：无效
            else return false;
        }
        return num && numAfterE;
    }
};
