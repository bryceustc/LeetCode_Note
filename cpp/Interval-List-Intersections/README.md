# 题目描述: 区间列表的交集

给定两个由一些 闭区间 组成的列表，每个区间列表都是成对不相交的，并且已经排序。

返回这两个区间列表的交集。

（形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b。两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）

**示例:**
```
输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
```
  
# 解题思路:
  
  猿辅导的面试题，利用双指针来做，
  

# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(n)
  
# 代码

### 双指针法
```c++
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int n = A.size();
        int m = B.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            if (start <= end) {
                res.push_back({start, end});
            }
            // 较长的区间还有可能和后边的区间有交集的
            // 较短的区间移动
            if (A[i][1] < B[j][1]) {
                i++;
            } 
            else {
                j++;
            }
        }
        return res;
    }
};
```
