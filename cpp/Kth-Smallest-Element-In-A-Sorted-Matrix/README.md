充分利用有序这一条件 利用二分查找这个

const countInMatrix = (matrix, midVal) => {
  const n = matrix.length;            // 这题是方阵 n行n列
  let count = 0;
  let row = 0;                        // 第一行
  let col = n - 1;                    // 最后一列
  while (row < n && col >= 0) {
    if (midVal >= matrix[row][col]) { // 大于等于当前行的最右
      count += col + 1;               // 不大于它的数增加col + 1个
      row++;                          // 比较下一行
    } else {                          // 干不过当前行的最右元素
      col--;                          // 留在当前行，比较左边一个
    }
  }
  return count;
};

const kthSmallest = (matrix, k) => {
  const n = matrix.length;
  let low = matrix[0][0];
  let high = matrix[n - 1][n - 1];
  while (low <= high) {
    let midVal = low + ((high - low) >>> 1);   // 获取中间值
    let count = countInMatrix(matrix, midVal); // 矩阵中小于等于它的个数
    if (count < k) {
      low = midVal + 1;
    } else {
      high = midVal - 1;
    }
  }
  return low;
};

```c++
class Solution {
   public:
    int countInMatrixeck(vector<vector<int>>& matrix, int mid, int n) {
        int i = 0;
        int j = n-1;
        int num = 0;
        while (i < n && j >= 0) {
            if (matrix[i][j] <= mid) {
                num += j + 1;
                i++;
            } else {
                j--;
            }
        }
        return num;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int count = countInMatrixeck(matrix,mid,n);
            if (count >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

```c++
class Solution {
   public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = 0;
        int j = n-1;
        int num = 0;
        while (i < n && j >= 0) {
            if (matrix[i][j] <= mid) {
                num += j + 1;
                i++;
            } else {
                j--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
