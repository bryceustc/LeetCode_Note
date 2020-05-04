# 题目描述:  有效的数独

判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

  - 数字 1-9 在每一行只能出现一次。
  - 数字 1-9 在每一列只能出现一次。
  - 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

数独部分空格内已填入了数字，空白格用 '.' 表示。

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

一个数独。


![](http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)

答案被标成红色。

说明:

- 给定的数独序列只包含数字 1-9 和字符 '.' 。
- 你可以假设给定的数独只有唯一解。
- 给定数独永远是 9x9 形式的。

# 解题思路:
  利用哈希表，三次p判断结果可以在一次迭代中实现。
  一次迭代主要是如何枚举子数独？
  可以使用 box_index = (row / 3) * 3 + cols / 3，其中 / 是整数除法。
  
  ![](https://pic.leetcode-cn.com/2b141392e2a1811d0e8dfdf6279b1352e59fad0b3961908c6ff9412b6a7e7ccf-image.png)
  

# 时间复杂度：
O(n*n)
# 空间复杂度
 O(n*n)
  
# 代码

```c++
class Solution {
public:
    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    vector<int> getNext(vector<vector<char>>& board)
    {
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }
    
    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (dfs(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};
```
### 参考

- [题解](https://leetcode-cn.com/problems/sudoku-solver/solution/37-by-ikaruga/)
