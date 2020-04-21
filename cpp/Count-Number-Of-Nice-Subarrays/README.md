# 题目描述:  统计「优美子数组」

给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

**示例 :**
```
输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
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
