# 题目描述:  拼写单词

给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。


**示例 :**
```
输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
```

# 解题思路:
  碰到这种需要统计字符次数的要先想到哈希表。
  
  对于一个单词 word，只要其中的每个字母的数量都不大于 chars 中对应的字母的数量，那么就可以用 chars 中的字母拼写出 word。所以我们只需要用一个哈希表存储 chars 中每个字母的数量，再用一个哈希表存储 word 中每个字母的数量，最后将这两个哈希表的键值对逐一进行比较即可。

# 时间复杂度：
  O(n) 其中 n 为所有字符串的长度和
# 空间复杂度
 O(S) 其中 S 为字符集大小
  
# 代码

### 哈希
```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        if (words.empty() || chars.empty()) return 0;
        unordered_map<char,int> m1;
        for (auto c : chars)
        {
            m1[c]++;
        }
        for(string word : words)
        {
            unordered_map<char,int> m2;
            for (char s : word)
            {
                m2[s]++;
            }
            bool is_res = true;
            for (char s : word)
            {
                if(m1[s]<m2[s])
                {
                    is_res=false;
                    break;
                }
            }
            if(is_res) res+=word.size();
        }
        return res;
    }
};
```

