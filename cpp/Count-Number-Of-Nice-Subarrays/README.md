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
1. 前缀和+哈希表

- 将奇数转换成1，偶数转换成0，则本题等价为和为k的连续子数组的种类。然后利用前缀和以及哈希表来做

2. 滑动窗口双指针

- 不断右移 right 指针来扩大滑动窗口，使其包含 k 个奇数；
- 若当前滑动窗口包含了 k 个奇数，则如下「计算当前窗口的优美子数组个数」：

  - 统计第 1 个奇数左边的偶数个数 leftEvenCnt。 这 leftEvenCnt 个偶数都可以作为「优美子数组」的起点，因此起点的选择有 leftEvenCnt + 1 种（因为可以一个偶数都不取，因此别忘了 +1 喔）。
  - 统计第 k 个奇数右边的偶数个数 rightEvenCnt 。 这 rightEvenCnt 个偶数都可以作为「优美子数组」的终点，因此终点的选择有 rightEvenCnt + 1 种（因为可以一个偶数都不取，因此别忘了 +1 喔）。
  - 因此「优美子数组」左右起点的选择组合数为 (leftEvenCnt + 1) * (rightEvenCnt + 1)。

# 时间复杂度：
 1. O(n)
 
 2. O(n)
# 空间复杂度
 1. O(n)
 
 2. O(1)
# 代码

### 前缀和+哈希表
```c++
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        vector<int> m(n+1);
        // m[i] 为 nums中[0..i]中奇数的个数，
        int sum = 0;
        m[0]=1; // 初始化为1考虑到边界情况，例如: nums = [1,1] k = 2。 
        // 遍历到i = 1时。res += sum >= k ? m[sum - k] : 0; 等价于 res += 2 >= 2 ? m[2 - 2] : 0
        for (int i=0;i<n;i++)
        {
            sum+=nums[i]&1;
            m[sum]++;
            res += sum>=k?m[sum-k]:0;
        }
        return res;
    }
};
```

### 滑动窗口
```c++
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res =0;
        int n = nums.size(), left = 0, right = 0, oddCnt=0;
        while(right<n)
        {
            // 右移窗口,每遇到一个奇数则 oddCnt++
            if (nums[right++]&1) oddCnt++;
            
            //  若当前滑动窗口 [left, right) 中有 k 个奇数了，进入此分支统计当前滑动窗口中的优美子数组个数。
            if (oddCnt==k)
            {
                int temp = right;
                // 先将滑动窗口的右边界向右拓展，直到遇到下一个奇数（或出界）
                // rightEvenCnt 即为第 k 个奇数右边的偶数的个数
                while(right<n && (nums[right]&1)==0)
                {
                    right++;
                }
                int rightEvenCnt = right-temp;
                
                // leftEvenCnt 即为第 1 个奇数左边的偶数的个数
                int leftEvenCnt = 0;
                while((nums[left]&1)==0)
                {
                    leftEvenCnt++;
                    left++;
                }
                // 第 1 个奇数左边的 leftEvenCnt 个偶数都可以作为优美子数组的起点
                // (因为第1个奇数左边可以1个偶数都不取，所以起点的选择有 leftEvenCnt + 1 种）
                // 第 k 个奇数右边的 rightEvenCnt 个偶数都可以作为优美子数组的终点
                // (因为第k个奇数右边可以1个偶数都不取，所以终点的选择有 rightEvenCnt + 1 种）
                // 所以该滑动窗口中，优美子数组左右起点的选择组合数为 (leftEvenCnt + 1) * (rightEvenCnt + 1)
                res += (leftEvenCnt+1) * (rightEvenCnt+1);
                // 此时 left 指向的是第 1 个奇数，因为该区间已经统计完了，因此 left 右移一位，oddCnt--
                left++;
                oddCnt--;
            }
        }
        return res;
    }
};
```
## 参考
  - [题解讨论](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/solution/hua-dong-chuang-kou-qian-zhui-he-bi-xu-miao-dong-b/) 
  - [滑动窗口框架套路详解](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485141&idx=1&sn=0e4583ad935e76e9a3f6793792e60734&chksm=9bd7f8ddaca071cbb7570b2433290e5e2628d20473022a5517271de6d6e50783961bebc3dd3b&scene=126&sessionid=1587516905&key=90f15a20186b1d46c2992f11e82b01a0cda6178792cdef35f4436e8185c7cc6e973a629da69bafba62e0b6551c49abdf6c71bd261ba3c3acf9539e3ecf9390d5761103a4d3a3c3eb9f0c41aadad3a4c5&ascene=1&uin=MjE1ODMxOTYzOA%3D%3D&devicetype=Windows+10&version=62080079&lang=zh_CN&exportkey=A4FXMMlE%2Bef9sSA4mIuJSO0%3D&pass_ticket=ppDnFMJpc9c%2Bn6RJFcuQ6KqAmN5hl%2BcvIiSNRu3bA2J3Np0Zr%2Fv7M6xJCQYQC60l)
