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

在solveSudoku函数中，首先对rows[i],cols[j],cells[i/3][j/3] 初始化存储状态，并且记录有待填入数字的数目，然后开始dfs深搜

dfs采用bool 形式，只要满足一种情况就可以结束递归，提高了程序的效率，GetNext函数是要选择可能性最少的数字开始填，（所谓的可能性最小其实要找出包含已知信息最多的坐标(i,j)这种位置，找出这个坐标位置后，GetPossibleStatus函数就是找出在这个坐标（i,j）这个位置的合适的数字来进行填写，然后就是回溯了。

fillnum函数就是更新rows[i],cols[j],cells[i/3][j/3]的状态信息，使之与board[i][j]的状态相对应。
  
图解：

![](https://pic.leetcode-cn.com/1fb1c64cfddb5c66b61bd769224724a05027172d6486feb19b3a16d9473372ee-%E5%9B%BE%E7%89%87.png)


# 时间复杂度：
O(n*n)
# 空间复杂度
 O(n*n)
  
# 代码

```c++
class Solution {
public:
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

    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if (cnt == 0) return true;//递归结束条件

        auto next = getNext(board);//找出可能性最小的位置（其实就是包含已知信息最多的位置，这样选择的次数是最少的，有点类似贪心的思想）

        auto bits = getPossibleStatus(next[0], next[1]);//找出这个坐标(i,j)可以填入的数字
        if(bits.count()==0) return false;

        for (int n = 0; n < bits.size(); n++)
        {
            if (!bits.test(n)) continue;    //第n位是否为1
            fillNum(next[0], next[1], n, true);//更新存储状态
            board[next[0]][next[1]] = n + '1';

            if (dfs(board, cnt - 1)) return true;
            fillNum(next[0], next[1], n, false);//撤销上一步的存储状态
            board[next[0]][next[1]] = '.';
        }
        return false;
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

    bitset<9> getPossibleStatus(int x, int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    void fillNum(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? (1) : (0);
        cols[y][n] = (fillFlag) ? (1) : (0);
        cells[x/3][y/3][n] = (fillFlag) ? (1): (0);
    }
private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
};
```
### 参考

- [题解](https://leetcode-cn.com/problems/sudoku-solver/solution/37-by-ikaruga/)
- [题解](https://leetcode-cn.com/problems/sudoku-solver/solution/zi-cong-wo-xue-hui-liao-hui-su-suan-fa-zhong-yu-hu/)
