# 题目描述:  回文子串

给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

**示例 1:**
```
输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
```

**示例 2:**
```
输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
```

  
# 解题思路:
思路一：找出所有的子串，然后判断有哪些子串是回文子串。

思路二：枚举每一个可能的回文中心，然后用两个指针分别向左右两边拓展，当两个指针指向的元素相同的时候就拓展，否则停止拓展。

思路三：使用数学方法，康托展开
 
# 时间复杂度：
  思路一：O(n^3)

  思路二：O(n<sup>2</sup>) 

  思路三：使用数学方法，康托展开，O(n)
# 空间复杂度
  思路一：O(n) 
  
  思路二：O(n)
  
  
# 代码

###  方法一： 暴力法
```c++
class Solution {
public:
    int countSubstrings(string s) {
        int res  = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string tmp = s.substr(i, j - i + 1);
                // cout << tmp << endl;
                if (helper(tmp)) res++;
            }
        }
        return res;
    }

    bool helper(string s) {
        int n =s.size();
        int l = 0, r = n -1;
        while (l <=r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
```

###  方法一改进版：回溯+剪枝+减去前k-1个枝（比较笨）
```c++
class Solution {
public:
    int res = 0;
    int countSubstrings(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            count (s, i, i); //回文串长度为奇数
            count(s, i, i+1);//回文串长度为偶数
        }
        return res;
    }

    void count(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
    }
};
```
