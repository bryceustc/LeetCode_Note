# 题目描述:  课程表 II

现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

**示例 1:**
```
输入: 2, [[1,0]] 
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
```

**示例 2:**
```
输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
```

  
# 解题思路:
 拓扑排序，此题与华为初赛的题类似需要计算入度，构建图。利用BFS来解决，不过有点不同。
 
- 传统BFS：把出列节点的下一层子节点推入 queue，不加甄别
- 拓扑排序：实施甄别和监控，新入度为 0 的先推入 queue
 
# 时间复杂度：
  O(n+m) 其中 n 为课程数，m 为先修课程的要求数
# 空间复杂度
  O(n+m)
  
# 代码

```c++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int,vector<int>> graph;  // 构建哈希表
        vector<int> indegree(numCourses,0); // 初始化入度数组
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;  // 计算入度
        }
        queue<int> q;
        for (int i=0;i<indegree.size();++i) // 起初推入所有入度为0的课
        {
            if (indegree[i]==0)  
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front(); // 出栈，代表选这门课
            res.push_back(u);  // 压入结果
            q.pop();
            for (int v : graph[u])
            {
                indegree[v]--;  // 将后续课程的入度 -1
                if (indegree[v]==0)  // 一旦减到0，让该课入列
                {
                    q.push(v);
                }
            }
        }
        if (res.size()<numCourses) return {}; // 选齐了就返回res，否则返回{}
        return res;
    }
};
```
# 参考

  -  [题解讨论](https://leetcode-cn.com/problems/course-schedule-ii/solution/bao-mu-shi-ti-jie-tuo-bu-pai-xu-si-lu-zen-yao-yi-2/)
