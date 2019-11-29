# 题目描述:在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
```
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
```

示例 2:
```
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
```
  
# 解题思路:
  [二分查找算法](./BinarySearch.md)
  
  1). 使用两次二分查找法
  
  2). 第一次二分查找目标值的左边界，第二次查找目标值的右边界。（注意：二分法的三种情况，查找某一个数，查找左边界，查找右边界）

# 时间复杂度：
  O(nlogn)
# 空间复杂度
  O(1)
# 代码

[C++](./Find-First-And-Last-Position-Of-Element-In-Sorted-Array.cpp)

[Python](./Find-First-And-Last-Position-Of-Element-In-Sorted-Array.py)

## C++:
### 方法一：两次二分查找
```c++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res = {-1,-1};
      int n = nums.size();
      if (nums.empty()) return res;
      int start = 0;
      int end = n;
      while (end > start)   // 寻找左边界，搜索区间为左闭右开
      {
        int mid = start + (end - start)/2;
        if (nums[mid]==target)
        {
            end = mid;
        }
        if (nums[mid]<target)
        {
            start = mid + 1;
        }
        if (nums[mid]>target)
        {
            end = mid;
        }
      }
      if (start==n || nums[start]!=target) return res;
      res[0] = start;
      start = 0;
      end = n;
      while(end > start) //寻找右边界，搜索区间为左开右闭
      {
        int mid = start + (end - start)/2;
        if (nums[mid]==target) 
        {
            start = mid + 1;
        }
        if (nums[mid] < target)
        {
            start = mid + 1;
        }
        if (nums[mid] > target)
        {
            end = mid;
        }
      }
      res[1] = end - 1;
      return res;
    }
};


int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res;
    res=Solution().searchRange(nums,target);
    int m = res.size();
    for (int i = 0; i < m; i++)
    {
        cout << res[i]<< endl;
    }
    system("pause");
    return 0;
}

```

## 方法二：线性扫描直接两次遍历，寻找左右边界
```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res = {-1,-1};
      int n = nums.size();
      if (nums.empty()) return res; 
      for(int i=0;i<n;i++)
      {
          if(nums[i]==target)
          {
              res[0] = i;
              break;
          }
      }
      if (res[0]==-1) return res;
      for (int j=n-1;j>=0 ;j--)
      {
          if (nums[j]==target) 
          {
              res[1] =j;
              break;
          }
      }
      return res;
    }
};
```



## Python
### 方法一：两次二分法
```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        res= [-1,-1]
        if n==0:
            return res
        start = 0
        end = n
        while end > start:
            mid=start + (end-start)//2
            if nums[mid]<target:
                start= mid +1
            else:
                end = mid
        if start == n or nums[start]!=target:
            return res
        res[0]=start
        start = 0
        end = n
        while end > start:
            mid = start + (end-start)//2
            if nums[mid]<=target:
                start=mid+1
            else:
                end = mid
        res[1] =end-1
        return res
```


# 参考：
 - [循环结构中break、continue、return和exit的区别](https://blog.csdn.net/hunanchenxingyu/article/details/8101795)
 
 - [时间复杂度和空间复杂度](https://blog.csdn.net/zolalad/article/details/11848739)
