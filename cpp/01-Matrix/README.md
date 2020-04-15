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
  理解题意：其实就是找到一个海洋区域，这个海洋区域到与它最近的陆地区域的距离是最大的。那么就是按照层序遍历，最后一个遍历到的海洋就是所求。
  
  二维表格上的问题，常用的算法是深度优先遍历、广度优先遍历和并查集，由于这里计算的结果和距离相关，显然使用广度优先遍历；
  
  一般而言，「广度优先遍历」求的是最短路径，但仔细一想，发现其实广度优先遍历也是适用的：
   - 求最短路径的时候，只要找到目标值，返回即可；
   - 求最长路径的时候，所有目标值都看完以后，才返回。
    
  广度优先遍历（BFS）逐层向外扩散的精准数学解释，每扩散一次，曼哈顿距离就加 1。
# 时间复杂度：
  O(m*n) 这里 m n 是方格的边长。二维表格里所有的元素都会被遍历一遍；
# 空间复杂度
 O(m*n) 最坏情况下，方格里全部是0时候，元素全部会进队列。
  
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

