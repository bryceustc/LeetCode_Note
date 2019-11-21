/// Source : https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
/// Author : bryce
/// Time   : 2019-11-21

/*
思路：
1. 
2. 
3. 

时间复杂度：

*/

// C++ Solution 1:
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = words.size();
        int m = s.size();
        int len = words[0].size();
        unordered_map <string, int> dict;
        for (auto word : words)  //也可以写成 for(auto &word : words)加&表示以引用访问
            dict[word]++;
        for (int i=0; i<=m-n*len;i++)
        {
            unordered_map<string,int> strdict;
            int j = 0;
            for (j=0;j<n;j++)
            {
                string t = s.substr(i+j*len,len);//获得字符串s中从第i+j*len位开始的长度为len的字符串
                if (dict.find(t)==dict.end()) break;
                //if (!dict.count(t)) break; find()返回值是一个迭代器，成功返回迭代器指向要查找的元素，失败返回的迭代器指向end。count()返回值是一个整数，1表示有这个元素，0表示没有这个元素。
                strdict[t]++;
                if (strdict[t]>dict[t]) break;
            }
            if (j==n) res.push_back(i);
        }
        return res;
    }
};
