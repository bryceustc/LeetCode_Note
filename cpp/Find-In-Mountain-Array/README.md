# 题目描述:  山脉数组中查找目标值

（这是一个 交互式问题 ）

给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

如果不存在这样的下标 index，就请返回 -1。

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：

首先，A.length >= 3

其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

- A[0] < A[1] < ... A[i-1] < A[i]
- A[i] > A[i+1] > ... > A[A.length - 1]

你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

- MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
- MountainArray.length() - 会返回该数组的长度


**示例 :**
```
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```
  
# 解题思路:

二分法：

首先使用二分法找出峰值，然后在左边升序区间查找，再在右边降序区间进行查找。

# 时间复杂度：
  O(log(n))
# 空间复杂度
  O(1)
  
# 代码

###  二分法
```c++
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
         //  找出峰值 与162题类似
        int start = 0;
        int end = n-1;
        while(start<end)
        {
            int mid  = start + (end-start)/2;
            if (mountainArr.get(mid)>mountainArr.get(mid+1))
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }
        int peek = start; 
        
        //  在左边升序区间进行查找
        start = 0;
        end = peek;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if (target==mountainArr.get(mid))
            {
                return mid;
            }
            else if (target<mountainArr.get(mid))
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        
        // 在右边降序区间进行查找
        start = peek;
        end = n-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if (target==mountainArr.get(mid))
            {
                return mid;
            }
            else if (target<mountainArr.get(mid))
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        // 没找到就返回-1
        return -1;
    }
};
```
# 参考

  -  [LeetCode-162-寻找峰值](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-Peak-Element/README.md)
