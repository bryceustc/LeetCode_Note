# 题目描述:  单词的压缩编码

给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
每个单词都是小写字母 。


**示例 :**
```
输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
```
# 解题思路:
  存储后缀
  
  字典树
# 代码

###  存储后缀
```c++
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if (words.empty()) return 0;
        int res = 0;
        unordered_set<string> s(words.begin(), words.end());
        for (const string& word : words)
        {
            for (int i=1;i<word.size();i++)
            {
                s.erase(word.substr(i));
            }
        }
        for (const string& word: s)
        {
            res += word.size() + 1;
        }
        return res;
    }
};
```
### 字典树
```c++
class TrieNode{
    TrieNode* children[26];
public:
    int count;
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = NULL;
        count = 0;
    }
    TrieNode* get(char c) {
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*, int> nodes;

        for (int i = 0; i < (int)words.size(); ++i) {
            string word = words[i];
            TrieNode* cur = trie;
            for (int j = word.length() - 1; j >= 0; --j)
                cur = cur->get(word[j]);
            nodes[cur] = i;
        }

        int ans = 0;
        for (auto& [node, idx] : nodes) {
            if (node->count == 0) {
                ans += words[idx].length() + 1;
            }
        }
        return ans;
    }
};
```
### 参考
  - [字典树题解](https://leetcode-cn.com/problems/short-encoding-of-words/solution/dan-ci-de-ya-suo-bian-ma-by-leetcode-solution/)
