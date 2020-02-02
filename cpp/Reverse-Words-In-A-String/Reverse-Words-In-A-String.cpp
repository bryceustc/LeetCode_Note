class Solution {
public:
    void  Reverse(string &s,int start,int end)
    {
        while(start < end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) 
    {
        string res;
        int n = s.size();
        int start=0,end=0;
        int x=0,y=0;
        while(x<n)
        {
            if (s[x]!=' ')
            {
                break;
            }
            x++;
        }
        s = s.substr(x);
        end = s.size()-1;
        // 整个句子翻转
        Reverse(s,0,end);
        while(y<s.size())
        {
            if (s[y]!=' ')
            {
                break;
            }
            y++;
        }
        s=s.substr(y);
        int m = s.size();
        int i=0;
        while (i<m)
        {
            while(i<m && s[i]== ' ')
            {
                i++;
            }
            start = end = i;
            while(i<m && s[i]!=' ')
            {
                i++;
                end++;
            }
            Reverse(s,start,end-1);
            for (int j=start;j<=end;j++)
            {
                res+=s[j];
            }
        }
        return res;
    }
};
// Solution 2:
class Solution {
public:
    void Reverse(string &s,int start,int end)
    {
        while(start<end)
        {
            swap(s[start++],s[end--]);
        }
    }
    
    string cleanSpaces(string &s)
    {
        int n = s.size();
        int i=0,j=0;
        while(j<n)
        {
            while(j<n && s[j] == ' ') j++; // 跳过空格
            while(j<n && s[j] != ' ')s[i++] = s[j++]; // 保留单词（非空格部分）
            while(j<n && s[j] == ' ') j++; // 跳过空格（主要是防止结尾有空格，然后再添加空格越界）
            if (j<n) s[i++] = ' '; // 补充空格
        }
        return s.substr(0,i);
    }
    
    string reverseWords(string s) 
    {
        int n = s.size();
        //翻转整个语句
        Reverse(s,0,n-1);
        // 翻转句中单词
        int start = 0, end = 0;
        int i=0;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++;
            start = end = i;
            while(i<n && s[i]!=' ')
            {
                i++;
                end++;
            }
            Reverse(s,start,end-1);
        }
        //清除多余空格
        s = cleanSpaces(s);
        return s;
    }
};
// Solution 3:
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        string ans="",temp;
        ss<<s;
        while(ss>>temp){
            ans=" "+temp+ans;
        }
        if(ans!="")
            ans.erase(ans.begin());
        return ans; 
    }
};
