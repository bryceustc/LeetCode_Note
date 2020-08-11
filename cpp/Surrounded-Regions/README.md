# 题目描述:  被围绕的区域

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。


**示例 1:**
```
X X X X
X O O X
X X O X
X O X X
```
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X

解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的
  
# 解题思路:
dfs，注意先从外部边界开始遍历，首先对边界上每一个'O'做深度优先搜索，将与其相连的所有'O'改为'#'。然后遍历矩阵，将矩阵中所有'O'改为'X',将矩阵中所有'#'变为'O'，这个题和岛屿数量题比较类似，要灵活掌握
# 时间复杂度：
O(mn)
# 空间复杂度
 O(mn)
  
# 代码

### 
```c++
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               // 从边缘o开始搜索
                bool isEdge = ( i==0 || i == m-1 || j == 0 || j == n-1);
                if ( isEdge &&  board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }

    }

    void dfs(vector<vector<char>> & board, int i, int j) {
        if (i <0 || i >= board.size() || j < 0 || j>= board[0].size() || board[i][j] == 'X' || board[i][j] == '#') {
            return;
        }
        board[i][j] = '#';
        dfs(board, i+1, j);
        dfs(board, i-1,  j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
```
