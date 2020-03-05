# 题目描述:  分糖果 II

排排坐，分糖果。

我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。

给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。

然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。

重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。

返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。


**示例 :**
```
输入：candies = 7, num_people = 4
输出：[1,2,3,1]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0,0]。
第三次，ans[2] += 3，数组变为 [1,2,3,0]。
第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
```
**示例 :**
```
输入：candies = 10, num_people = 3
输出：[5,2,3]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0]。
第三次，ans[2] += 3，数组变为 [1,2,3]。
第四次，ans[0] += 4，最终数组变为 [5,2,3]。
```

# 解题思路:
  1. 直接模拟法 
  
  2. 数学法
# 时间复杂度：
  1: O(max(sqrt(G),N))G 为糖果数量，N为人数。
  
  2: O(N)
# 空间复杂度
  1: O(n)
  
  2: O(n)
  
# 代码

## [C++](./Distribute-Candies-To-People.cpp):
### 模拟法
```c++
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res (num_people, 0);
        vector<int> temp (num_people, 0);
        int i=0;
        int a=0;
        while(candies>0)
        {
            i %=num_people;
            if (i==0)
            {
                a =temp[num_people-1]+1;
            }
            else
            {
                a = temp[i-1]+1;
            }
            candies -= a;
            if (candies<0)
            {
                res[i]+=candies;
            }
            temp[i] = a;
            res[i] += temp[i];
            i++;
        }
        return res;
    }
};
```
###  精简版
```c++
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int i =0;
        while (candies>i)
        {
            res[i%num_people] +=  i+1;
            candies-=i+1;
            i++;
        }
        res[i%num_people] += candies;
        return res;
    }
};
```

### 数学方法
```c++
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        // how many people received complete gifts
        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            // complete rows
            d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
            // cols in the last row
            if (i < cols) d[i] += i + 1 + rows * n;
        }
        // remaining candies 
        d[cols] += remaining;
        return d;
    }
};
```
## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Distribute-Candies-To-People/Distribute-Candies-To-People.py)
###  模拟法
```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0]*num_people
        i =0
        while candies >i:
            res[i%num_people] += i+1
            candies -= i+1
            i+=1
        res[i%num_people]+= candies
        return res
```
## 数学法
```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        # 为了方便理解，把num_people赋值给n，即n个小朋友
        n = num_people
        # 套用上面推出来的公式，直接计算可以完整发放糖果的次数p
        p = int((2 * candies + 0.25)**0.5 - 0.5) 
        # 继续套用公式，算出完整发放糖果以后剩余的糖果数量
        R = int(candies - (p + 1) * p * 0.5)
        # 迭代rows轮，cols是倒霉孩子的下标
        rows, cols = p // n, p % n
        
        # 小朋友们端好了碗，等你发糖
        kids = [0] * n
        for i in range(n):
            # 性感coder，在线发糖
            kids[i] = (i + 1) * rows + int(rows * (rows - 1) * 0.5) * n
            # 最后一轮or在p<n时的第一轮
            if i < cols:
                d[i] += i + 1 + rows * n
        # 最后的那个倒霉孩子开心的拿到了R颗糖       
        kids[cols] += R
        return kids
```

# 参考

  -  [数学方法理解](https://leetcode-cn.com/problems/distribute-candies-to-people/solution/xiang-xi-jie-shi-shu-xue-fang-fa-zen-yao-zuo-gao-z/)
