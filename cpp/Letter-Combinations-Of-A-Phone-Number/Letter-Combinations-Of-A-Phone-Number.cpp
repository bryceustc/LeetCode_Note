/// Source : https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
/// Author : bryce
/// Time   : 2019-11-08

/*
用迭代来求解，遍历digits中所有的数字，建立一个临时的字符串数组temp,然后通过数字到dict中取出字符串str，然后遍历取出字符串所有字符，
再遍历当前结果res中的每一个字符串，将字符加到后面，并加入到临时字符串数组temp中。取出的字符串str遍历完成后，将临时字符串数组赋值给结果res
*/


// C++ Solution 1:
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            int n = res.size();
            string str = dict[digits[i] - '2'];
            for (int j = 0; j < n;j++)
            {
                string temp = res.front();    //vec.front() 返回第一个元素的值，与begin()函数有区别，begin()函数返回的是第一个元素的迭代器
                res.erase(res.begin());      //删除第一个元素
                for (int k = 0; k < str.size();k++)
                {
                    string a = temp + str[k];
                    res.push_back(a);
                }
            }
        }
        return res;      
    }
};

// C++ Solution 2:
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
                                      {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> result{""};
        if(digits.size()==0) return {};
        for(int i=0;i<digits.size();i++){
            vector<string> temp;
            string str = mp[digits[i]];
            for(int j=0;j<str.size();j++){
                for(string s:result)          // C++11 里面的for的新写法，表示依次取出字符串数组result中的元素
                    temp.push_back(s+str[j]);
            }
            result = temp;
        }
        return result;
    }
};

/*
其实可以将此题看成求解一棵树的所有root(root可以看做是空)到叶子的路径。  
例如当`digits = "23"`时，树应该是这个样子:
```
          root
        /   |   \
  2:   a    b    c
      /|\  /|\  /|\
  3:  def  def  def
```
所以就可以用DFS求解这题了。
*/

