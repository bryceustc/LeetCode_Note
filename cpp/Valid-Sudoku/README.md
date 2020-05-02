# 题目描述:  有效的数独

判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

  - 数字 1-9 在每一行只能出现一次。
  - 数字 1-9 在每一列只能出现一次。
  - 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

数独部分空格内已填入了数字，空白格用 '.' 表示。

**示例 :**
```
输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
```

说明:

- 一个有效的数独（部分已被填充）不一定是可解的。
- 只需要根据以上规则，验证已经填入的数字是否有效即可。
- 给定数独序列只包含数字 1-9 和字符 '.' 。
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

### 暴力模拟
```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       int n = board.size();
       for (int i=0;i<n;i++)
       {
           unordered_set<char> s1, s2;
           for (int j=0;j<n;j++)
           {
               char c = board[i][j];
               if (c!='.'&&!s1.count(c))
               {
                   s1.insert(c);
               }
               else if (s1.count(c))
               {
                   return false;
               }
               char d = board[j][i];
               if (d!='.'&&!s2.count(d))
               {
                   s2.insert(d);
               }
               else if (s2.count(d))
               {
                   return false;
               }
           }
       }
       for (int i=0;i<n;i+=3)
       {
           for (int j=0;j<n;j+=3)
           {
               if (helper(i,j,board))
               {
                   return false;
               }
           }
       }
       return true;
    }

    bool helper(int i, int j, vector<vector<char>> &board)
    {
        int x = i+3;
        int y = j+3;
        unordered_set<char> s;
        for (int a=i;a<x;a++)
        {
            for (int b=j;b<y;b++)
            {
                char c = board[a][b];
                if (c!='.'&&!s.count(c))
                {
                    s.insert(c);
                }
                else if (s.count(c))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
```

### 一次迭代
```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<unordered_set<char>> row(9);
       vector<unordered_set<char>> col(9);
       vector<unordered_set<char>> box(9);
       for (int i=0;i<9;i++)
       {
           for (int j=0;j<9;j++)
           {
               char c = board[i][j];
               int index = (i/3)*3 + (j/3);
               if (c!='.'&&!row[i].count(c)&&!col[j].count(c)&&!box[index].count(c))
               {
                   row[i].insert(c);
                   col[j].insert(c);
                   box[index].insert(c);
               }
               else if (row[i].count(c)||col[j].count(c)||box[index].count(c))
               {
                   return false;
               }
           }
       }
       return true;
       }
};
```
### 参考

- [题解](https://leetcode-cn.com/problems/valid-sudoku/solution/you-xiao-de-shu-du-by-leetcode/)
