# 题目描述:  字母异位词分组

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。


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
  - 不考虑答案输出的顺序

  
# 解题思路:
  方法一：建立哈希表，可以发现如果把错位词的字符顺序重新排列，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法，由于错位词重新排序后都会得到相同的字符串，以此作为 key，将所有错位词都保存到字符串数组中，建立 key 和当前的不同的错位词集合个数之间的映射，这里之所以没有建立 key 和其隶属的错位词集合之间的映射，是用了一个小 trick，从而避免了最后再将 HashMap 中的集合拷贝到结果 res 中。当检测到当前的单词不在 HashMap 中，此时知道这个单词将属于一个新的错位词集合，所以将其映射为当前的错位词集合的个数，然后在 res 中新增一个空集合，这样就可以通过其映射值，直接找到新的错位词集合的位置，从而将新的单词存入结果 res 中

# 时间复杂度：
  O(NLlogL)
  NN 是字符串个数，LL 是字符串平均长度。对于每个字符串，哈希表和vector的插入操作复杂度都是 O(1)，排序复杂度是 O(LlogL)。所以总时间复杂度是 O(NLlogL)
# 空间复杂度
  O(NL)
  
# 代码

## [C++](./Group-Anagrams.cpp):

### 方法一： 哈希表
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        unordered_map<string,int> record;
        for (auto & str : strs)
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            if (record.find(temp) == record.end())
            {
                record[temp] = res.size();
                res.push_back({});
            }
            res[record[temp]].push_back(str);
        }
        return res;
    }
};
```

### 方法二：哈希表
```c++
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        int n = strs.size();
        unordered_map<string,vector<string>> record;
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            record[temp].push_back(str);
        }
        for (auto& m:record)
        {
            res.push_back(m.second);  //m是record里边的元素，利用操作符'.'进行索引第2个,下标i是迭代器，用法类似指针，用i->second索引
        }
        // for (auto i = record.begin();i!=record.end();i++)
        // {
        //     res.push_back(i->second);
        // }    
        return res;
    }
};
```

### 方法三：质数
```c++
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        int n = strs.size();
        unordered_map<string,vector<string>> record;
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            record[temp].push_back(str);
        }
        for (auto& m:record)
        {
            res.push_back(m.second);  //m是record里边的元素，利用操作符'.'进行索引第2个,下标i是迭代器，用法类似指针，用i->second索引
        }
        // for (auto i = record.begin();i!=record.end();i++)
        // {
        //     res.push_back(i->second);
        // }    
        return res;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Group-Anagrams/Group-Anagrams.py)
### 方法一： 哈希表
```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        n = len(strs)
        if n==0:
            return res
        dic = {}
        for s in strs:
            t = s
            t = "".join(sorted(t))
            if t not in dic:
                dic[t] = len(res)
                res.append([])
            res[dic[t]].append(s)
        return res
```

### 方法二 : 哈希表
```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        dic = {}
        m ={}
        n = len(strs)
        if n==0: 
            return res
        for s in strs:
            t = s
            t = "".join(sorted(t))
            if t not in dic:
                dic[t] = [s]
            else:
                dic[t].append(s)
        res = list(dic.values())
        return res
```
