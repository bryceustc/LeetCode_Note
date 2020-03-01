# 题目描述:  通过投票对团队排名

现在有一个特殊的排名系统，依据参赛团队在投票人心中的次序进行排名，每个投票者都需要按从高到低的顺序对参与排名的所有团队进行排位。

排名规则如下：

  - 参赛团队的排名次序依照其所获「排位第一」的票的多少决定。如果存在多个团队并列的情况，将继续考虑其「排位第二」的票的数量。以此类推，直到不再存在并列的情况。
  - 如果在考虑完所有投票情况后仍然出现并列现象，则根据团队字母的字母顺序进行排名。
给你一个字符串数组 votes 代表全体投票者给出的排位情况，请你根据上述排名规则对所有参赛团队进行排名。

请你返回能表示按排名系统 排序后 的所有团队排名的字符串。

**示例 1:**
```
输入：votes = ["ABC","ACB","ABC","ACB","ACB"]
输出："ACB"
解释：A 队获得五票「排位第一」，没有其他队获得「排位第一」，所以 A 队排名第一。
B 队获得两票「排位第二」，三票「排位第三」。
C 队获得三票「排位第二」，两票「排位第三」。
由于 C 队「排位第二」的票数较多，所以 C 队排第二，B 队排第三。
```
**示例 2:**
```
输入：votes = ["WXYZ","XYZW"]
输出："XWYZ"
解释：X 队在并列僵局打破后成为排名第一的团队。X 队和 W 队的「排位第一」票数一样，但是 X 队有一票「排位第二」，而 W 没有获得「排位第二」。 
```

**示例 3:** 
```
输入：votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
输出："ZMNAGUEDSJYLBOPHRQICWFXTVK"
解释：只有一个投票者，所以排名完全按照他的意愿。
```

# 解题思路:
1、本题首先创建一个map.

char用来定位队员，map<int,int>用来累计成绩（int1用来定位排名，int2用来累计对应排名的成绩。

2、 二重循环，将每个队员累计的成绩得出

3、 对成绩排序，最后返回string串。

# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Rank-Teams-By-Votes.cpp):
###  自定义
```c++
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string res = votes[0];
        int n = votes[0].size();
        map<char, map<int, int>> m;
        for (auto s : votes)
        {
            for (int i=0;i<n;i++)
            {
                m[s[i]][i]++;
            }
        }
        // [&] 任何被使用到的外部变量都隐式地以引用方式加以引用。
        sort (res.begin(), res.end(), [&] (char a, char b)->bool
        {
            for (int i=0;i<n;i++)
            {
                if(m[a][i]  > m[b][i]) return true;
                if (m[a][i] < m[b][i]) return false;
            }
            return a<b;
        });
        return res;
    }
};
```

# 参考

  [Lambda 函数与表达式](https://www.runoob.com/cplusplus/cpp-functions.html)
