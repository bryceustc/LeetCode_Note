# 题目描述:  使数组唯一的最小增量

给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。

返回使 A 中的每个值都是唯一的最少操作次数。


**示例 :**
```
输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
```
**示例 :**
```
输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
```

# 解题思路:


# 时间复杂度：
  1：O(nlogn)
  
  2: O(n)
# 空间复杂度
  1:O(1)
  
  2:O(n)
# 代码

### 排序
```c++
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        // 先排序
        sort(A.begin(), A.end());
        int res = 0;
        for (int i=1;i<n;i++)
        {
            // 遍历数组，若当前元素小于等于它的前一个元素，则将其变为前一个数+1
            if (A[i]<=A[i-1])
            {
                int pre = A[i];
                A[i] = A[i-1]+1;
                res += A[i] - pre;
            }
        }
        return res;
    }
};
```
###  线性探测法(状态压缩)
```c++
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        int res = 0;
        // -1表示空位
        vector<int> pos(80000, -1);   // 80000 是因为最坏情况是40000个40000
        // 遍历每个数字a对其寻地址得到位置b, b比a的增量就是操作数。
        for (int a: A)
        {
            int b = findPos(a, pos);
            res += b-a;
        }
        return res;
    }
    // 线性探测寻址(状态压缩)
    int findPos(int a, vector<int> &pos)
    {
        int b = pos[a];
        // a对应的位置pos[a]是空位，直接放入
        if (b==-1)
        {
            pos[a] = a;
            return a;
        }
        // 向后寻址
        // 因为pos[a]中标记了上次寻址得到的空位，因此从pos[a]+1开始寻址就行了（不需要从a+1开始）
        b = findPos(b+1, pos);
        // 寻址后的新空位要重新赋值给pos[a]，路径压缩就是体现在这里。
        pos[a] = b;
        return b;
    }
};
```

## 参考
  - [题解](https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/ji-shu-onxian-xing-tan-ce-fa-onpai-xu-onlogn-yi-ya/)
