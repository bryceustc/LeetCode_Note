# 题目描述:  移动零

给定一个数组 ``nums``，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

**示例 :**
现有矩阵 matrix 如下：
```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```
**说明 :**

1. 必须在原数组上操作，不能拷贝额外的数组。

2. 尽量减少操作次数。

  
# 解题思路:
此题与剑指offer第21题类似

方法一：构建辅助数组，遍历，两次原数组，一次添加非零元素，一次添加0元素，时间复杂度为O(n)

方法二：利用插入排序的思想，外层循环遍历数组，找``0``元素所在的位置；内层循环找当前``0``元素所在位置之后的第一个非零元素。当当前位置的值为``0``时执行内层循环，假设当前位置``i``的值``num[i]=0``，内层循环的``j = i++``，即从当前0元素所在的下一个位置开始查找非零元素；当``nums[j] != 0``时，``nums[i] = nums[j]``，``nums[j]=0``，即交换``nums[i]``、``nums[j]``的值，并退出内层循环，执行外层循环。 时间复杂度(n<sup>2</sup>)

方法三：利用冒泡排序的思想，两层循环，内层从最后开始交换，时间复杂度为O(n<sup>2</sup>)
 
# 时间复杂度：
  方法一： On)
  
  方法二： O(n<sup>2</sup>)
  
  方法三： O(n<sup>2</sup>) 
# 空间复杂度
  方法一：O(n)
  
  方法二：O(1)
  
  方法三：O(1)
  
# 代码

## [C++](./Move-Zeroes.cpp):

###  方法一： 构建辅助数组：
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        vector<int> res;
        int n = nums.size();
        for (int i =0;i<n;i++)
        {
            if (nums[i]!=0)
              res.push_back(nums[i]);
        }
        for (int i =0;i<n;i++)
        {
            if (nums[i]==0)
              res.push_back(nums[i]);
        }
    }
};
```

###  方法二： 插入排序
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        for (int i =0;i<n;i++)
        {
            if (nums[i]==0)
            {
                for (int j=i+1;j<n;j++)
                {
                    if (nums[j]!=0)
                    {
                        int temp = nums[j];
                        for (int k=j;k>i;k--)
                        {
                            nums[k]=nums[k-1];
                        }
                        nums[i] = temp;
                        break;
                    }
                }
            }
        }    
    }
};
```

###  方法三： 冒泡排序
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        for (int i =0;i<n;i++)
        {
            for (int j=n-1;j>i;j--)
            {
                if (nums[j]!=0 && nums[j-1]==0)
                {
                    swap(nums[j],nums[j-1]);
                }
            }
        }    
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Move-Zeroes/Move-Zeroes.py)
###  方法一：构造辅助数组法（未通过OJ )
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        res = []
        n = len(nums)
        if n==0:
            return
        for i in range(n):
            if nums[i]!=0:
                res.append(nums[i])
        for i in range(n):
            if nums[i]==0:
                res.append(nums[i])
        nums=res
```
### 方法二 ：插入排序
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        for i in range(0,n):
            if nums[i]==0:
                for j in range(i+1,n):
                    if nums[j]!=0:
                        temp = nums[j]
                        for k in range (j,i,-1):
                            nums[k] = nums[k-1]
                        nums[i] = temp
                        break
```

### 方法三 ：冒泡排序(未通过OJ，超出时间限制)
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        for i in range(0,n):
                for j in range(n-1,i,-1):
                    if nums[j]!=0 and nums[j-1]==0:
                        temp = nums[j]
                        nums[j] = nums[j-1]
                        nums[j-1] = temp
```

# 参考

  -  [调整数组顺序使奇数位于偶数前面](https://github.com/bryceustc/CodingInterviews/blob/master/ReorderArray/README.md)




