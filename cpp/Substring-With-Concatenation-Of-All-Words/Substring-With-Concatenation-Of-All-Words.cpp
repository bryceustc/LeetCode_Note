/// Source : https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
/// Author : bryce
/// Time   : 2019-11-21

/*
思路：
1. 假设words数组中有n个单词，每个单词长度为len,则此题实质为找出所有长度为n*len的子串，使得其刚好是由words数组中的单词组成。
2. 判断字符串s中长度为len的子串是否为words数组中的单词，因为无序要求，利用HashMap，同时考虑可能有重复的单词，就需要建立所有单词和其出现次数的映射，
   即统计每个单词出现的个数
3. 遍历s中所有长度为n*len的子串，当剩余子串长度小于n*len时，就无需在判断（注意size()返回的是无符号型，记得转换为int）
4. 对于每个遍历到的长度为n*len的子串，每次取长度为len的子串，看看是否是words中的单词，方便判断，建立另一个HashMap，当取出单词不在words中，跳出循环，
   否则在新建的HashMap中映射值+1，还要判断映射值如果超过原HashMap中的值，即当前子串在words数组中出现，但是出现次数超过words中的次数，也要跳出循环
5. 在循环外，若j正好等于n，则表示检测的n个长度为len的子串，都是words中的单词，并且刚好构成words，将当前位置i加入结果res中

时间复杂度：
枚举所有起点O(m)，每次匹配至多匹配n个单词，那么时间复杂度为 O(m∗n∗len)
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
        unordered_map<string,int> word_dict;
        for (auto word:words) //也可以写成 for(auto &word : words)加&表示以引用访问
            word_dict[word]++;
        for (int i=0;i<m-n*len+1;i++)
        {
            unordered_map<string,int> str_dict;
            int j = 0;
            for (j=0;j<n;j++)
            {
                string t = s.substr(i+j*len,len);
                if (word_dict.find(t)==word_dict.end()) break;
                //if (!dict.count(t)) break; find()返回值是一个迭代器，成功返回迭代器指向要查找的元素，失败返回的迭代器指向end。count()返回值是一个整数，1表示有这个元素，0表示没有这个元素。
                str_dict[t]++;
                if (str_dict[t]>word_dict[t]) break;
            }
            if (j==n) res.push_back(i);
        }
        return res;
    }
};
