class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.empty()) return res;
        vector<int> dx (4,0);
        vector<int> dy (4,0);
        dx[0]=1;
        dx[1]=-1;
        dy[2]=1;
        dy[3]=-1;
        queue<pair<int,int>> q; // pair的用法,将2个数据组合成一个数据，当需要这样的需求时就可以使用pair，如stl中的map就是将key和value放在一起来保存
        int m = grid.size();
        int n = grid[0].size();
        // 把腐烂的🍊加入队列中，作为开始扩散的起点
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        //从腐烂的🍊开始感染，其实就是一个bfs求无权图最短路的问题
        while(!q.empty())
        {
            int size = q.size(); // 感染🍊的上下左右算一层
            for (int i=0;i<size;i++)
            {
                pair<int,int> d = q.front();
                q.pop();
                for (int k=0;k<4;k++)
                {
                    int x = d.first + dx[k];
                    int y = d.second + dy[k];
                    if (x>=0 && x<m && y>=0 && y<n && grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        q.push(make_pair(x,y));
                    }
                }
            }
            if (!q.empty()) res++;
        }
        //遍历矩阵，判断是否有🍊还未被感染，也就是是否还有grid[i][j] = 1的地儿
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]==1)
                    return -1;
            }
        }
        // for(auto row : grid) 
        // {
        //     for (int i : row)
        //         if (i == 1) return -1;
        // }
        return res;
    }
};
