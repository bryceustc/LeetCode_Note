# 题目描述:  下一个更大元素 III

给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。如果不存在这样的32位整数，则返回-1。
**示例 :**
```
输入: 12
输出: 21

输入: 21
输出: -1
```
# 解题思路:
 - 将数字拆成位数组nums
 - 寻找数组的最后一个顺序对[i, i + 1]，记录左侧的下标i
 - 将i右侧数组进行翻转，右侧就变成了升序序列（因为i右侧不再有顺序对，也就是说都是逆序对了，因此翻转了就是升序序列）
 - i右侧二分查找到比nums[i]大的最小值nums[j]，交换nums[i]，nums[j]就是结果
  
# 代码

###  
```c++
class Solution {
public:
    vector<int> digits(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int nextGreaterElement(int n) {
        vector<int> nums = digits(n);
        int N = nums.size();
        int l = -1;
        for (int i = 1; i < N; ++i) {
            if (nums[i] > nums[i - 1]) {
                l = i - 1;
            }
        }
        if (l == -1) return -1;
        reverse(nums.begin() + l + 1, nums.end());
        int r = upper_bound(nums.begin() + l + 1, nums.end(), nums[l]) - nums.begin();
        swap(nums[l], nums[r]);
        long res = 0;
        for (int i = 0; i < N; ++i) {
            res = 10 * res + (long)nums[i];
        }
        return res > INT_MAX ? -1 : res;
    }
};
```
