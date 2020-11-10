### 下一个排列

![](https://pic.leetcode-cn.com/e56a66ed318d1761cd8c8f9d1521f82a30c71ecc84f551912b90d8fe254c8f3d-image.png)

- 从后往前找到第一个【相邻升序对】，即A[i]<A[i+1]。此时A[i+1,end)为降序。
- 在区间[i+1,end)中，从后往前找到第一个大于A[i]的元素A[j]
- 交换A[i]和A[j]，此时A[i+1,end)一定还是降序，因为A[j]是从右侧起第一个大于A[i]的值
- 反转A[i+1,end)，变成升序

时间复杂度: O(n)

空间复杂度: O(1)

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2, j = n - 1;
        for (i = n - 2; i >= 0; i--) {
            // 第一个相邻的升序对
            if (nums[i+1] > nums[i]) {
                // 从后向前找第一个大的
                for (j = n - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        break;
                    }
                }
                // 交换
                swap(nums[i], nums[j]);
                // 重新排序，因为是降序，所以直接反转就可以
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        // 没有逆序对，直接反转
        reverse(nums.begin(), nums.end());
    }
};
```
