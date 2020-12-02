# 题目描述:  拼接最大数

给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

**示例 :**
```
输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]

输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]

输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]

```
# 解题思路:
  单调栈+归并思想，注意字典序的使用
  
# 代码

###  
```c++
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int m = nums1.size();
        int n = nums2.size();
        for (int i = 0; i <= k; i++) {
            if ( i <= m && k - i <= n) {
                // nums1中长度为i的最大子序列A
                vector<int> A = pick_max(nums1, i);
                // nums2中长度为k-i的最大子序列B
                vector<int> B = pick_max(nums2, k - i);
                vector<int> temp;
                // 对两个子序列进行归并
                // lexicographical_compare：比较两个序列的字典序大小
                auto iter1 = A.begin(), iter2 = B.begin();
                while (iter1 != A.end() || iter2 != B.end()){
                    temp.push_back(lexicographical_compare(iter1, A.end(), iter2, B.end()) ? *iter2++ : *iter1++);
                }
                // 如果归并后的最大子序列大于目前已找到的最大子序列，则更新解
                res = lexicographical_compare(res.begin(), res.end(), temp.begin(), temp.end()) ? temp : res;
            }
        }
        return res;
    }
    // 与402题相似移除k位数字相似
    vector<int> pick_max(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res(k);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while(!s.empty() && k < n - i + s.size() && s.top() < nums[i]) {
                s.pop();
            }
            if (s.size() < k) {
                s.push(nums[i]);
            }
        }
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            res[--k] = t;
        }
        return res;
    }
};
```
### 参考：
   - [详细题解](https://leetcode-cn.com/problems/create-maximum-number/solution/cshou-xian-qiu-jie-zi-wen-ti-zai-he-bing-zi-wen-ti/)
