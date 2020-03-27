# 题目描述:  卡牌分组

给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。


**示例 :**
```
输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
```
**示例 :**
```
输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

```

# 解题思路:
统计各个数出现的次数，然后求次数之间是否存在公约数

# 时间复杂度：
 O(n)
# 空间复杂度
  O(n)
# 代码

### 排序
```c++
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        // 可以用数组
        unordered_map<int, int> m;
        for (int a : deck)
        {
            m[a]++;
        }
        int x = m[deck[0]];
        for (int a : deck)
        {
            if (m[a]>0)
            {
                x = __gcd(x, m[a]);
                if (x==1)
                    return false;
            }
        }
        return x>=2;
    }
};
```
## 参考
  - [题解](https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/solution/qiu-jie-zui-da-gong-yue-shu-java-by-liweiwei1419/)
