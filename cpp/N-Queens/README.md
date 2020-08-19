### 题目描述 N皇后

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)


### 代码
第一种搜索顺序
```c++
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cols(n,0);
        vector<int> dgs(2*n,0);
        vector<int> udgs(2*n,0);
        string s (n, '.');
        vector<string> out(n, s);
        dfs(0, res, cols, dgs, udgs, n, out);
        return res;
    }

    void dfs(int u,  vector<vector<string>> &res,  vector<int> &cols, vector<int> &dgs, vector<int> &udgs, int n, vector<string> &out) {
        if (u == n) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!cols[i] && !dgs[u+i] && !udgs[u - i+ n]) {
                cols[i] = dgs[u+i] = udgs[u - i+ n] = 1;
                out[i][u] = 'Q';
                dfs(u+1, res, cols, dgs, udgs, n, out);
                cols[i] = dgs[u+i] = udgs[u - i+ n] = 0;
                out[i][u] = '.';
            }
        }
    }
};
```
acwing第一种搜索顺序
```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 20;
char g[N][N];
int col[N], dg[N], udg[N];
int n;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            cout << g[i] << endl;
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u+i] && !udg[u - i + n]) {
            g[u][i] = 'Q';
            col[i] = dg[u+i] = udg[u-i+n] = 1;
            dfs(u+1);
            col[i] = dg[u+i] = udg[u-i+n] = 0;
            g[u][i] = '.';
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
```
第二种搜索顺序
```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 20;
char g[N][N];
int row[N], col[N], dg[N], udg[N];
int n;

void dfs(int x, int y, int s) {
    if (y == n) y = 0, x++;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; i++) {
                cout << g[i] << endl;
            }
            puts("");
        }
        return;
    }

    // not set queen
    dfs(x, y + 1, s);

    //set queen
    if (!row[x] && !col[y] && !dg[x+y] && !udg[y - x + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x+y] = udg[y - x + n] = 1;
        dfs(x, y+1, s + 1);
        row[x] = col[y] = dg[x+y] = udg[y - x + n] = 0;
        g[x][y] = '.';
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}
```
