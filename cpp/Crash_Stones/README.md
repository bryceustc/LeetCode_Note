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
转换成01背包问题，求两堆石头的最小差值。由于石头总和为sum.则问题转换成了背包最多装sum / 2的石头,stones数组里有一大堆石头。求如何装能装下最多重量石头。

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
using namespace std;

class Solution{
    public:
        int test(int n, vector<int> stones)
        {
            int sum = 0;
            for (int stone:stones)
            {
                sum+=stone;
            }
            int maxCapcity = sum/2;
            vector<int> dp (maxCapcity+1,0);
            for (int i=0;i<n;i++)
            {
                for (int j=maxCapcity;j>=stones[i];j--)
                {
                    dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
                }
            }
            return sum - 2*dp[maxCapcity];
        }
};

int main()
{
    int n;
    cin >> n;
    vector<int> stones(n);
    for(int i=0;i<n;i++)
    {
        cin >> stones[i];
    }
    int res = Solution().test(n, stones);
    cout << res << endl;
    return 0;
}
```
## 参考
  - [最后一块石头的重量 II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Last-Stone-Weight-II/README.md)
  - [题解](https://leetcode-cn.com/problems/last-stone-weight-ii/solution/dong-tai-gui-hua-bei-bao-wen-ti-xiang-jie-by-jiach/)
