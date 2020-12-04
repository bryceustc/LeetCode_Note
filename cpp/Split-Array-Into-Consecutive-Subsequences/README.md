# 题目: 659. 分割数组为连续子序列

## 题目描述：
给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。

如果可以完成上述分割，则返回 true ；否则，返回 false 。

  **示例：**
  ```
输入: [1,2,3,3,4,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3
3, 4, 5

输入: [1,2,3,3,4,4,5,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3, 4, 5
3, 4, 5

  ```
  
  
# 解题思路:
首先使用两个哈希 map count和tail

- count[i]：存储原数组中数字i出现的次数
- tail[i]：存储以数字i结尾的且符合题意的连续子序列个数

先去寻找一个长度为3的连续子序列 i, i+1, i+2，找到后就将 count[i], count[i+1], count[i+2] 中对应数字消耗1个（即-1），并将 tail[i+2] 加 1，即以 i+2 结尾的子序列个数 +1。

如果后续发现有能够接在这个连续子序列的数字 i+3，则延长以 i+2 为结尾的连续子序列到 i+3，此时消耗 nc[i+3] 一个，由于子序列已延长，因此tail[i+2] 减 1，tail[i+3] 加 1

在不满足上面的情况下

如果 count[i] 为 0，说明这个数字已经消耗完，可以不管了

如果 count[i] 不为 0，说明这个数字多出来了，且无法组成连续子序列，所以可以直接返回 false 了

# 时间复杂度：
O(n)
# 空间复杂度
 O(n)
# 代码
# C++: 
###  贪心
```c++
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count, tail;
        // count[num] num出现的次数
        for (auto &num : nums) {
            count[num]++;
        }
        for (int &num: nums) {
            //此元素没有剩余，已经被使用完了
            if (count[num] == 0) {
                continue;
            } else if (count[num] > 0 && tail[num-1] > 0) {
                //存在以num - 1结尾的连续子序列（长度不小于3），则将num放入
                count[num]--;
                tail[num-1]--;
                tail[num]++;
            } else if (count[num] > 0 && count[num+1] > 0 && count[num+2] > 0) {
                //否则查找后面两个元素，凑出一个合法的序列
                count[num]--;
                count[num+1]--;
                count[num+2]--;
                tail[num+2]++;
            } else {
                //两种方法都不行，则凑不出，比如[1,2,3,4,4,5]中的第二个4
                return false;
            }
        }
        return true;
    }
};
```
