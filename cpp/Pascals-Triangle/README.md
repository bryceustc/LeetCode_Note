# 题目描述:  118. 杨辉三角

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

**示例 :**
```
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

  
# 解题思路:
  数学规律
# 时间复杂度：
  O(n^2) 
# 空间复杂度
  O(1)
  
# 代码

###  数学模拟zhao
```c++
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        if (n <= 0) return res;
        for (int i = 0; i < n; i++) {
            vector<int> out(i+1,1);
            for (int j = 1; j < i; j++) {
                out[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(out);
        }
        return res;
    }
};
```
