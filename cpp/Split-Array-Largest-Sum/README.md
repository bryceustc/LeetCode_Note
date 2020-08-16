# 题目描述:  分割数组的最大值

给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。

数组长度 n 满足以下条件:

- 1 ≤ n ≤ 1000
- 1 ≤ m ≤ min(50, n)


**示例 1:**
```
输入:
nums = [7,2,5,10,8]
m = 2

输出:
18

解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
```

# 解题思路:
最小化最大值，最大化最小值是二分的常用操作，注意！！！
# 时间复杂度：
O(nlogn)
# 空间复杂度
 O(nlogn)
  
# 代码

### 
```c++
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long l = 0;
        long long r = 0;
        for (long long num : nums) {
            r += num;
            l = max(l, num);
        }
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (check(nums, mid,m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool check(vector<int>& nums, int x, int m) {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > x) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }
};
```
