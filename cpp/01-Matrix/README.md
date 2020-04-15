# 题目描述:  01 矩阵

给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

**示例 :**
```
输入:
0 0 0
0 1 0
0 0 0

输出:

0 0 0
0 1 0
0 0 0
```

**示例 :**
```
输入:
0 0 0
0 1 0
1 1 1

输出:
0 0 0
0 1 0
1 2 1
```


# 解题思路:
  此题和[地图分析](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/As-Far-From-Land-As-Possible/README.md) 类似！那道题是可以理解为需要找到每个 0 最近的 1，而这道题是找每个 1 最近的 0。
  
广度优先搜索
- 对于 「Tree 的 BFS」 （典型的「单源 BFS」） 大家都已经轻车熟路了：

首先把 root 节点入队，再一层一层无脑遍历就行了。
- 对于 「图 的 BFS」 （「多源 BFS」） 做法其实也是一样，与 「Tree 的 BFS」的区别注意以下两条就 ok

Tree 只有 1 个 root，而图可以有多个源点，所以首先需要把多个源点都入队；

Tree 是有向的因此不需要标识是否访问过，而对于无向图来说，必须得标志是否访问过哦！并且为了防止某个节点多次入队，需要在其入队之前就将其设置成已访问

首先把每个源点 0入队，然后从各个 0同时开始一圈一圈的向 1扩散（每个 1 都是被离它最近的 0扩散到的 ）本题是可以直接修改原数组 vector<int> matrix 来记录距离和标志是否访问的，这里要注意先把 matrix 数组中 1 的位置设置成 -1 （设成Integer.MAX_VALUE，m * n，10000都行，只要是个无效的距离值来标志这个位置的 1 没有被访问过就行）
# 时间复杂度：
  O(m\*n) 这里 m n 是方格的边长。二维表格里所有的元素都会被遍历一遍；
# 空间复杂度
 O(m\*n) 最坏情况下，方格里全部是0时候，元素全部会进队列。
  
# 代码

### bfs
```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int>> q;
        vector<int> dx {1,-1,0,0};
        vector<int> dy {0,0,1,-1};
        // 首先将所有的 0 都入队，并且将 1 的位置设置成 -1，表示该位置是 未被访问过的 1
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (matrix[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
                else
                {
                    matrix[i][j]=-1;
                }
            }
        }
        while(!q.empty())
        {
            int size = q.size();
            for (int i=0;i<size;i++)
            {
                pair<int,int> d = q.front();
                q.pop();
                // 如果四邻域的点是 -1，表示这个点是未被访问过的 1
                // 所以这个点到 0 的距离就可以更新成 matrix[d.first][d.second] + 1。
                for (int k=0;k<4;k++)
                {
                    int x = d.first + dx[k];
                    int y = d.second + dy[k];
                    if (x>=0 && x<m && y>=0 && y<n && matrix[x][y]==-1)
                    {
                        matrix[x][y] = matrix[d.first][d.second]+1;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }

        return matrix;
    }
};
```

