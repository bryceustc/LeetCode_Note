# 题目描述:  合并排序的数组

给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

**示例 :**
```
输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
```

# 解题思路:
1： 调用sort：

最直观的方法是先将数组 B 放进数组 A 的尾部，然后直接对整个数组进行排序

2：双指针:

 从后向前遍历，每次取两者之中的较大者放进 A 的最后面
# 时间复杂度：
  1: O((m+n)log(m+n))
  
  2: O(m+n)
# 空间复杂度
  1: O(log(m+n))
  
  2: O(m+n)
  
# 代码

## [C++](./Sorted-Merge-Lcci.cpp):
### 直接合并后排序
```c++
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i=0;i<n;i++)
        {
            A[m+i]= B[i];
        }
        sort(A.begin(),A.end());
    }
};
```
###  双指针
```c++
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m-1;
        int j = n-1;
        int index =  m+n-1;
        while (i>=0 && j>=0)
        {
            if(A[i]>=B[j])
            {
                A[index--] = A[i--];
            }
            else
            {
                A[index--] = B[j--];
            }
        }
        // 下面这个while没必要写，这时候index 和i是相等的。
        // while (i>=0)  A[index--] = A[i--];
        while (j>=0)  A[index--] = B[j--];
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Sorted-Merge-Lcci/Sorted-Merge-Lcci.py)
###  直接合并后排序
```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:] = B
        A .sort()
```
## 双指针
```python
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m-1
        j = n-1
        index = m+n-1
        while i>=0 and j>=0:
            if A[i] >= B[j]:
                A[index] = A[i]
                index-=1
                i-=1
            else:
                A[index] = B[j]
                index -=1
                j-=1
        # 比较完B还有剩下的，全填到A前面即可
        A[:j+1] = B[:j+1]
```

# 参考

  -  [合并两个有序链表](https://github.com/bryceustc/CodingInterviews/blob/master/MergeSortedLists/README.md)
