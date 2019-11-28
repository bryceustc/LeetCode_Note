// C++ Solution 1: 
# 题目描述:数组中重复的数字

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
## 方法一：两次二分查找
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    }
};


int main()
{
    vector<int> nums = {2,3,1,0,2,5,3};
    int n = nums.size();
    vector<int> res;
    Solution().Duplication1(nums,n,res);
    int m = res.size();
    for (int i = 0; i < m; i++)
    {
        cout << res[i]<< endl;
    }
    system("pause");
    return 0;
}

```

# 参考：
 - [循环结构中break、continue、return和exit的区别](https://blog.csdn.net/hunanchenxingyu/article/details/8101795)
 
 - [时间复杂度和空间复杂度](https://blog.csdn.net/zolalad/article/details/11848739)
