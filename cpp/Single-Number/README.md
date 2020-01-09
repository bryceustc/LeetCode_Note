# 题目描述:  只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

**说明** 
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例 1:**
现有矩阵 matrix 如下：
```
输入: [2,2,1]
输出: 1
```
**示例 2:**
现有矩阵 matrix 如下：
```
输入: [4,1,2,1,2]
输出: 4
```
  
# 解题思路:

方法一：利用哈希表来做，``unordered_map<int,int> map``,``map[nums[i]]==1``。

方法二：对每一行使用一次二分查找，时间复杂度为O(m\*logn)

方法三：根据简单的例子寻找规律，从右上角开始寻找，时间复杂度为O(m+n)
 
# 时间复杂度：
  方法一： On)
  
  方法二： O(m\*logn)
  
  方法三： O(m+n) 
# 空间复杂度
  方法一：O(n)
  
# 代码

## [C++](./Single-Number.cpp):

###  方法一： 哈希表(unordered_map)
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =0;
        unordered_map<int,int> map;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int i=0;i<n;i++)
        {
            if (map[nums[i]]==1)
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
```
### 方法一：哈希表(unordered_set)
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        unordered_set<int> st;
        for (int num : nums) 
        {
            if (st.find(num)!=st.end()) // if (st.count(num))
                st.erase(num);
            else 
                st.insert(num);
        }
        res = *st.begin();
        return res;
    }
};
```



###  方法二： 遍历+一次二分查找法
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty()) return false;
            int m = matrix.size();
            int n = matrix[0].size();
            for (int i=0;i<m;i++)
            {
                int start = 0;
                int end = n-1;
                while(end>=start)
                {
                    int mid = start+(end-start)/2;
                    if (matrix[i][mid]==target)
                        return true;
                    else if (matrix[i][mid]<target)
                        start=mid+1;
                    else if (matrix[i][mid]>target)
                        end=mid-1;
                }
            }
            return false;        
    }
};
```

###  方法三： 从右上角开始查找
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0)
        {
            if (matrix[i][j]==target)
                return true;
            if (matrix[i][j]>target)
                j--;  //左移
            else
                i++; // 下移
        }
        return false;
    }
};
```

###  方法四： 从左下角开始查找
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i=m-1,j=0;
        while(i>=0&& j<n)
        {
            if (matrix[i][j]==target)
                return true;
            if (matrix[i][j]>target)
                i--;  //上移
            else
                j++; // 右移
        }
        return false;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Search-A-2D-Matrix-II/Search-A-2D-Matrix-II.py)
###  方法一：暴力遍历法
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        for i in range(m):
            for j in range(n):
               if matrix[i][j]==target:
                   return True
        return False
```
### 方法二 ：遍历+一次二分查找
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        for i in range(m):
            start = 0
            end = n-1
            while end>=start:
                mid = start + (end-start)//2
                if matrix[i][mid] == target:
                    return True
                if matrix[i][mid]<target:
                    start=mid+1
                if matrix[i][mid]>target:
                    end=mid-1
        return False
```

### 方法三 ：右上角查找
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        i=0
        j=n-1
        while i<m and j>=0:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j]>target:
                j-=1
            else:
                i+=1
        return False
```

### 方法四 ：左下角查找
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        if m==0:
            return False
        n=len(matrix[0])
        i=m-1
        j=0
        while i>=0 and j<n:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j]>target:
                i-=1
            else:
                j+=1
        return False
```

# 参考

  -  [二维数组中的查找](https://github.com/bryceustc/CodingInterviews/blob/master/FindInPartiallySortedMatrix/README.md)
  -  [搜索二维矩阵](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Search-A-2D-Matrix/README.md)



