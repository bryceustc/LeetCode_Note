# 题目描述:  面试题 10.02. 变位词组

编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。


**示例 :**
```
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

**说明：**
- 所有输入均为小写字母。
- 不考虑答案输出的顺序。

# 解题思路:
哈希表模拟法
# 时间复杂度：
  O(nklogk) n是数组长度，k是字符串中最长的字符串长度
# 空间复杂度
  O(nk)
  
# 代码
### 模拟法
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res ;
        unordered_map<string, vector<string>> mp;
        for (string str : strs)  {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};
```
