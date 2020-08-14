# 题目描述:  转变数组后最接近目标值的数组和

给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。

如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

请注意，答案不一定是 arr 中的数字。


**示例 :**
```
输入：arr = [4,9,3], target = 10
输出：3
解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
```

**示例：**
```c++
输入：arr = [2,3,5], target = 10
输出：5
```
  
# 解题思路:

参考weiwei哥的题解使用，使用二分法：

如果选择一个阈值 value ，使得它对应的 sum 是第 1 个大于等于 target 的，那么目标值可能在 value 也可能在 value - 1。

# 时间复杂度：
  O(nlog(n))
# 空间复杂度
  O(1)
  
# 代码

###  二分法
```c++
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = *max_element(arr.begin(), arr.end());
        while (l  < r) {
            int mid = l + (r -l) / 2;
            // 计算第 1 个使得转变后数组的和大于等于 target 的阈值 threshold
            int sum = helper(arr, mid);
            if (sum < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int sum1 = helper(arr, l);
        int sum2 = helper(arr, l-1);
        // 比较阈值线分别定在 left - 1 和 left 的时候与 target 的接近程度
        if (abs(sum1 - target) >= abs(sum2 - target)) {
            return l -1;
        }
        return l;
    }
    int helper(vector<int> &arr, int mid) {
        int sum = 0;
        for (int &num: arr) {
            sum += min(num, mid);
        }
        return sum;
    }
};
```

# 参考

  -  [题解](https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/solution/er-fen-cha-zhao-by-liweiwei1419-2/)
