# 题目描述:  排序数组

给你一个整数数组 nums，将该数组升序排列。

**示例 :**
```
输入：nums = [5,2,3,1]
输出：[1,2,3,5]
```

# 解题思路:
各类排序算法

# 时间复杂度：
 O(nlogn)
# 空间复杂度
  O(1)
# 代码

### 快排
```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quicksort(nums, 0, n-1);
        return nums;
    }
    void quicksort(vector<int> &nums, int low, int high)
    {
        if (low>=high) return;
        int l=low, r=high, pivot = nums[l];
        while(l<r)
        {
            while(l<r && nums[r] >= pivot)
            {
                r--;
            }
            nums[l] = nums[r];
            while(l<r && nums[l] < pivot)
            {
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        quicksort(nums, low,l-1);
        quicksort(nums, l+1, high);
    }
};
```

### 插排
```c++

```
## 参考
  - [常见排序算法](https://github.com/bryceustc/CodingInterviews/blob/master/Sort/README.md)
