# 题目描述:  翻转字符串里的单词

给定一个字符串，逐个翻转字符串中的每个单词。

**示例 1:**
```
输入: "the sky is blue"
输出: "blue is sky the"
```
**示例 2:**
```
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
```
**示例 3:**
```
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
```
**说明** 
  - 无空格字符构成一个单词。
  - 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
  - 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
  
# 解题思路:
此题与剑指Offer第五十题类似，但比那个要难一点，因为题目要求删除多余空格，比那一题多一个要求。
思路应该比较清晰：
1) 翻转整个句子
2) 翻转句中单词
3) 删除多余的空格

方法一：先去除首尾的空格，可利用trim函数。但是trim函数一直使用不成功。所以我用了比较笨的方法，先将原字符串开头空格去掉，利用s.substr(x),然后将整个字符串翻转，在删除开头的空格（也就是原尾部空格字符），然后再利用s.substr(y),将首尾的空格去除干净。然后再新建一个空字符串，用start和end记录单词的起始和截止位置，碰到连续空格跳过，传递给res，返回结果。

方法二：同方法一，思路更加清晰

方法三：字符流，用stringstream来做
 
# 时间复杂度：
  不好分析时间复杂度，应该源大于O(n)接近n！
# 空间复杂度
  方法一：O(n)
  
  方法二：O(1)
  
# 代码

## [C++](./Reverse-Words-In-A-String.cpp):

###  方法一： 直接法，方法比较啰嗦冗余。
```c++
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
```
### 方法一：将首尾空格去除写在一个里边了，稍微精简了一点点，注意string中substr的用法，s.substr(2,4)  取s字符第2个位置往后边4位。
```c++
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
        int x=0,y=n-1;
        int count = 0;
        while(x<n && y>=0)
        {
            if (s[x]==' ')
            {
                x++;
            }
            if (s[y]==' ')
            {
                y--;
                count++;
            }
            if (s[x]!=' ' && s[y]!=' ')
            {
                break;
            }
        }
        s = s.substr(x,n-count);
        int m = s.size();
        // 整个句子翻转
        Reverse(s,0,m-1);
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
```



###  方法二： 三个函数，1) 翻转整个句子 ；2) 翻转句中单词；3) 删除多余的空格，思路比较清晰
```c++
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
```
### 方法三：字符流
```c++
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
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Reverse-Words-In-A-String/Reverse-Words-In-A-String.py)
###  方法一：
```python
class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s)
        n = len(s)
        self.Reverse(s,0,n-1)
        i =0
        while i<n:
            while i<n and s[i]==' ':
                i+=1
            start = end = i
            while i<n and s[i]!= ' ':
                i+=1
                end+=1
            self.Reverse(s,start,end-1)
        s = self.cleanSpaces(s)
        return s
    def Reverse(self,s,start,end):
        while start<end:
            s[start],s[end] = s[end],s[start]
            start+=1
            end-=1
    def cleanSpaces(self,s):
        n = len(s)
        i=0
        j=0
        while j<n:
            while j<n and s[j]==' ':
                j+=1
            while j<n and s[j]!=' ':
                s[i]=s[j]
                i+=1
                j+=1
            while j<n and s[j]==' ':
                j+=1
            if j<n:
                s[i] = ' '
                i+=1
        return "".join(s[:i])
```
### 方法二 ：利用split和reverse
```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
        ## Python split() 通过指定分隔符对字符串进行切片,分隔符，默认为所有的空字符，包括空格、换行(\n)、制表符(\t)等。
        ## 字符串翻转的三种方法：1) [::-1]切片 2) 递归 3) 借用列表，使用reverse()方法 l=list(s) l.reverse() print("".join(l))
```
# 参考

  -  [C++ 学习笔记之——字符串和字符串流](https://segmentfault.com/a/1190000017271382)
  -  [C++ string 类中substr的使用方法](https://blog.csdn.net/yyhaohaoxuexi/article/details/51416874)
  -  [Python split()方法](https://www.runoob.com/python/att-string-split.html)
  -  [Python字符串反转的3种方法](https://www.jianshu.com/p/c61279736a03)
  -  [剑指offer_50题——翻转单词顺序](https://github.com/bryceustc/CodingInterviews/blob/master/ReverseWordsInSentence/README.md)




