# 题目:考试成绩

## 题目描述：

现在你的班级刚刚参加了一个只有单选题的考试。班级一共n个学生，考试有m个问题。每个题目都有5个可选答案（A，B，C，D，E）。并且每个题目只有一个正确答案。每个题目的分数并不一样，第i个题目的分数用a[i]表示。如果题目没答对该题会获得0分。
考试结束后，每个学生都记得自己的答案，但是他们还不知道正确答案是什么。如果非常乐观的考虑，他们班级最多可能得到多少分呢？
**输入描述：**
```
第一行包含2个正整数，n和m。(1 <= n, m <= 1000，n是班级中学生数量，m是题目的数量)

下面n行数据每行包含一个string si，表示第i个学生的答案。si的第j个字符表示该学生第j个题目的答案。
```

**输出描述：**
```
一个正整数，全班学生最大的可能获得的分数总和。
```
**示例：**
```
输入：

2 4
ABCD
ABCE
1 2 3 4

输出：

16

说明：

最优的答案是ABCD，这样2个学生的总分是16。
  ```
  
# 解题思路:
哈希思想，统计每道题全班选择最多的为答案

# 时间复杂度：
O(mn)
# 空间复杂度
 O(n)
# 代码
###  
```c++
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
        long long test(int n, int m, vector<string> s, vector<int> score)
        {
            long long res = 0;
            for (int i=0;i<m;i++)
            {
                vector<int> temp(5);// ABCDE五个字母
                for (int j=0;j<n;j++)
                {
                    temp[s[j][i]-'A']++;
                }
                int most_ans = *max_element(temp.begin(),temp.end());
                // sort(temp.begin(),temp.end());
                // int most_ans = temp.back();
                res+=most_ans*score[i];
            }
            return res;
        }
};
 
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<int>score(m);
    for (int j = 0; j < m; j++)
        cin >> score[j];
    long long res = Solution().test(n,m,s,score);
    cout << res << endl;
    return 0;
}
```
