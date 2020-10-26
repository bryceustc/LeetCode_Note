# 题目描述:  有多少小于当前数字的数字

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

**示例 1:**
```
输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
```
**示例 2:**
```
输入：nums = [6,5,4,8]
输出：[2,1,0,3]
```

**示例 3: **
```
输入：nums = [7,7,7,7]
输出：[0,0,0,0]
```

**提示:** 

  - 给定的日期是 1971 年到 2100 年之间的有效日期。

# 解题思路:
直接暴力法

计数排序

注意到数组元素的值域为 [0,100][0,100][0,100]，所以可以考虑建立一个频次数组 cntcntcnt ，cnt[i]cnt[i]cnt[i] 表示数字 iii 出现的次数。那么对于数字 iii 而言，小于它的数目就为 cnt[0...i−1]cnt[0...i-1]cnt[0...i−1] 的总和。
# 时间复杂度：
  O(n^2)
  
  O(n)
# 空间复杂度
  O(n)
  
# 代码
```c++
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    if (nums[j] < nums[i]) {
                        t++;
                    }
                }
            }
            res[i] = t;
        }
        return res;
    }
};
```

计数排序
```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101,0);
        vector<int> res;
        int n = nums.size();
        // 初始化计数桶
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        // 累加处理计数桶，使得 cnt[i] 表示比 i 小的数字的个数
        int count = 0;
        for (int i = 0; i <= 100; i++) {
            int tmp = cnt[i];
            cnt[i] = count;
            count += tmp;
        }
        // 遍历 nums，取出对应桶 cnt[i] 里的结果即可
        for (int i = 0; i < n; i++) {
            res.push_back(cnt[nums[i]]);
        }
        return res;
    }
};
```
# 参考

  [scanf 用法及陷阱（转）](https://www.cnblogs.com/vanishfan/archive/2013/03/04/2942492.html)
  [C语言函数sscanf()的用法](https://www.cnblogs.com/lyq105/archive/2009/11/28/1612677.html)
  [C++中c_str()函数的用法](https://blog.csdn.net/JIEJINQUANIL/article/details/51547027)

