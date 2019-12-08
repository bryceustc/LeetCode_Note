// Solution 1:
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


// Solution 2:
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
