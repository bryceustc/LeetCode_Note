# 题目:石头碰撞

## 题目描述：

给定一组石头，每个石头有一个正数的重量。每一轮开始的时候，选择两个石头一起碰撞，假定两个石头的重量为x，y，x<=y,碰撞结果为
1. 如果x==y，碰撞结果为两个石头消失
2. 如果x != y，碰撞结果两个石头消失，生成一个新的石头，新石头重量为y-x

最终最多剩下一个石头为结束。求解最小的剩余石头质量的可能性是多少。
**输入描述：**
```
第一行输入石头个数(<=100)

第二行输入石头质量，以空格分割，石头质量总和<=10000
```

**输出描述：**
```
最终的石头质量
```
**示例：**
```
输入：

6
2 7 4 1 8 1

输出：

1
```
  
# 解题思路:


# 时间复杂度：
O(mn)
# 空间复杂度
 O(n)
# 代码
###  
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
    public:
        long long test(int n, int m, vector<string> s, vector<int> scores)
        {
            long long res = 0;
            for (int i=0;i<m;i++)
            {
                vector<int> temp(5);  // 固定选项ABCDE，所以需要大小为5就可以。
                for (int j=0;j<n;j++)
                {
                    temp[s[j][i]-'A']++;
                }
                int most_ans = *max_element(temp.begin(),temp.end());
                res += most_ans*scores[i];
            }
            return res;
        }
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> scores(m);
    for (int i=0;i<n;i++)
    {
        cin >> s[i];
    }
    for (int j=0;j<m;j++)
    {
        cin >> scores[j];
    }
    long long res = Solution().test(n,m,s,scores);
    cout << res << endl;
    return 0;
}
```
