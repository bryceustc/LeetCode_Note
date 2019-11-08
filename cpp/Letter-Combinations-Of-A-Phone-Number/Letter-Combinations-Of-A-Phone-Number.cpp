/// Source : https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
/// Author : bryce
/// Time   : 2019-11-08

/*
用迭代来求解，遍历digits中所有的数字，建立一个临时的zufy
*/


// C++ Solution 1:
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            int n = res.size();
            string str = dict[digits[i] - '2'];
            for (int j = 0; j < n; j++) {
                string tmp = res.front();
                res.erase(res.begin());
                for (int k = 0; k < str.size(); k++) {
                    res.push_back(tmp + str[k]);
                }
            }
        }
        return res;
    }
};
