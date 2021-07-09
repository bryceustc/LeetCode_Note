##题目描述
数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。

示例1：
```
输入：[1,2,5,9,5,9,5,5,5]
输出：5
```

示例2：
```
输入：[3,2]
输出：-1
```

## 解题思路
摩尔投票法
由于题目要求时间复杂度 O(n)和空间复杂度 O(1)，因此符合要求的解法只有 Boyer-Moore投票算法。

Boyer-Moore投票算法的基本思想是：在每一轮投票过程中，从数组中删除两个不同的元素，直到投票过程无法继续，此时数组为空或者数组中剩下的元素都相等。

- 如果数组为空，则数组中不存在主要元素；
- 如果数组中剩下的元素都相等，则数组中剩下的元素可能为主要元素。

## 代码

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1;
        int cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                res = num;
            }
            if (num == res) {
                cnt++;
            } else {
                cnt--;
            }
        }
        cnt = 0;
        for (int num : nums) {
            if (num == res) {
                cnt++;
            }
        }
        if (cnt > nums.size() / 2) return res;
        return -1;
    }
};
```
