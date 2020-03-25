# 题目描述:  三维形体的表面积

在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

请你返回最终形体的表面积。

**示例 :**
```
输入：[[2]]
输出：10

输入：[[1,2],[3,4]]
输出：34
```
# 解题思路:
  直接模拟法
  
  对于顶面和底面的表面积，如果 v > 0，那么顶面和底面各贡献了 1 的表面积，总计 2 的表面积；
  
  对于四个侧面的表面积，只有在相邻位置的高度小于 v 时，对应的那个侧面才会贡献表面积，且贡献的数量为 v - nv，其中 nv 是相邻位置的高度。我们可以将其写成 max(v - nv, 0)。
  
# 代码

###  
```c++
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[] {1,-1,0,0};
        int dy[] {0,0,1,-1};
        int  res =0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]>0)
                {
                    // 上下两个面是一定贡献的
                    res += 2;
                    // 判断剩余四个面，四个面如果相邻的高于当前，就会为负数不会贡献
                    for (int k=0;k<4;k++)
                    {
                        int near_i = i + dx[k];
                        int near_j = j + dy[k];
                        int near_v = 0;
                        if (near_i>=0 && near_i<n && near_j>=0 && near_j<n)
                        {
                            near_v = grid[near_i][near_j];
                        }
                        res += max(grid[i][j]- near_v, 0);
                    }
                }
            }
        }
        return res;
    }
};
```

