# 题目描述:  最后一块石头的重量

有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

  - 如果 x == y，那么两块石头都会被完全粉碎；
  - 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
  
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

# 解题思路:
模拟法

# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## C++
### 排序
```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int res = 0;
        while(stones.size()>1)
        {
            sort(stones.begin(),stones.end());
            int y = stones.back();
            stones.pop_back();
            int x = stones.back();
            stones.pop_back();
            if (x!=y)
            {
                int s3 = y-x;
                stones.push_back(s3);
            }
        }
        if(!stones.empty()) res = stones[0];
        return res;
    }
};
```
### 大顶堆
```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int res = 0;
        // 大顶堆
        priority_queue<int, vector<int>> q;
        for (int stone : stones)
        {
            q.push(stone);
        }
        while(q.size()>1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x!=y)
            {
                int z = y-x;
                q.push(z);
            }
        }
        if (!q.empty()) res = q.top();
        return res;
    }
};
```
