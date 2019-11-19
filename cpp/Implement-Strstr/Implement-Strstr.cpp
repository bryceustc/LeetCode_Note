/// Source : https://leetcode-cn.com/problems/implement-strstr/
/// Author : bryce
/// Time   : 2019-11-19

/*
思路(暴力枚举法)：
1. 如果needle为空，直接返回0
2. 如果haystack为空或者子串长度大于母串长度则返回-1
3. 遍历haystack字符串，后对于每一个字符，都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，
  如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即i.
4. 跳出循环则返回-1

时间复杂度：
暴力枚举O(nm)

*/
// C++ Solution 1:
class Solution {
public:
    int strStr(string haystack, string needle) {
      int m = needle.size();
      int n = haystack.size();
      if (needle.empty()) return 0;
      if (haystack.empty() || m > n) return -1;
      for (int i = 0; i < n; i++)
      {
        int j = 0;
        int k = i;
        while (haystack[k] == needle[j] && j<m)
        {
          j++;
          k++;
        }
        if (j==m) return i;
      }
      return -1;
    }
};

// C++ Solution 2:
// 其实可以不用遍历整个母字符串，而是遍历到剩下的长度和子字符串相等的位置即可，这样可以提高运算效率
class Solution {
public:
    int strStr(string haystack, string needle) {
      int m = needle.size();
      int n = haystack.size();
      if (needle.empty()) return 0;
      if (haystack.empty() || m > n) return -1;
      for (int i =0; i < n-m+1;i++)
      {
        int j = 0;
        int k = i;
        while (haystack[k] == needle[j] && j < m)
        {
          j++;
          k++;
        }
        if (j==m) return i;
      }
      return -1;
    }
};

//C++ Solution 3: (KMP算法)[https://blog.csdn.net/v_july_v/article/details/7041827]
class Solution {
public:
    int strStr(string haystack, string needle) {
         int n = haystack.size(), m = needle.size();
        if (m == 0)
            return 0;
        vector<int> next(m);
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < m; i++) {
            while (j > -1 && needle[i] != needle[j + 1]) j = next[j];
            if (needle[i] == needle[j + 1]) j++;
            next[i] = j;
        }
        j = -1;
        for (int i = 0; i < n; i++) {
            while (j > -1 && haystack[i] != needle[j + 1]) j = next[j];
            if (haystack[i] == needle[j + 1]) j++;
            if (j == m - 1)
                return i - m + 1;
        }
        return -1;
    }
};
