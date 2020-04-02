# 题目描述:  生命游戏

根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

 - 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
 - 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
 - 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 - 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

# 解题思路:

直接根据规则更新原始数组，那么就做不到题目中说的 同步 更新。假设你直接将更新后的细胞状态填入原始数组，那么当前轮次其他细胞状态的更新就会引用到当前轮已更新细胞的状态，但实际上每一轮更新需要依赖上一轮细胞的状态，是不能用这一轮的细胞状态来更新的。

![](https://pic.leetcode-cn.com/Figures/289/Game_of_life_3.png)


# 时间复杂度：
  O(mn) 
# 空间复杂度
  O(1) 原地修改空间复杂度为O(1)
  
# 代码

## C++:
###  
```c++
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
        利用一个 two bits 的状态机来记录细胞状态, 第一位表示
        下一状态, 第二位表示当前状态:
        00: dead (next state) <- dead (current state)
        01: dead (next state) <- live (current state) 
        10: live (next state) <- dead (current state)
        11: live (next state) <- live (current state) 
        初始情况对应就是 00 和 01 (默认下一状态是 dead state)
        统计每个位置周围的 live 细胞数决定高位置 1 (live)还是 
        0 (dead), 最后右移一位即为最终状态, 注意不需要考虑 01
        以及 00 的情况, 因为已经默认下一状态为 dead.
        */
        int m = board.size();
        int n = board[0].size();
        if (m<1) return;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int lives = helper(board,i,j);
                // live -> live 规则2
                if ((board[i][j]&1)==1)
                {
                    if (lives>=2 && lives <=3)
                    {
                        board[i][j]=3;
                    }
                    // 周围活细胞过多或过少都会死，因为原数据是01，所以这里不用额外赋值。
                }
                //  dead -> live 规则4
                else
                {
                    if (lives == 3)
                    {
                        board[i][j]=2;
                    }
                }
            }
        }
        // 重置矩阵
        for (int i=0; i<m;i++)
        {
            for (int j=0; j<n;j++)
            {
                // 右移一位
                board[i][j]>>=1;
            }
        }
    }
    int helper(vector<vector<int>> &board, int i, int j)
    {
        int count = 0;
        for (int k=0;k<8;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x<0 || x>=board.size() || y<0 || y>=board[0].size()) continue;
            count += (board[x][y] & 1);
        }
        return count;
    }
private:
    vector<int> dx {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> dy {0, 0, 1, -1, 1, -1, -1, 1};
};
```

### 合并一起
```c++
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m<1) return;
        int n = board[0].size();
        vector<int> dx {1,-1,0,0,1,1,-1,-1};
        vector<int> dy {0,0,1,-1,1,-1,-1,1};
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int cnt = 0;
                for (int k=0;k<8;k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x<0 || x>=m || y<0 || y>=n) continue;
                    cnt += board[x][y]&1;
                }
                if (board[i][j]==1)
                {
                    if (cnt>=2&&cnt<=3)
                    {
                        board[i][j] = 3; // 11
                    }
                }
                else
                {
                    if (cnt ==3)
                    {
                        board[i][j]=2;// 10
                    }
                }
            }
        }
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                board[i][j]>>=1;
            }
        }
    }
};
```
## 参考
  - [题解讨论](https://leetcode-cn.com/problems/game-of-life/solution/sheng-ming-you-xi-by-leetcode-solution/)
