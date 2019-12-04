# 题目描述: 接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

![rainwater](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/rainwatertrap.png)

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

**示例 :**
```
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
```
  
# 解题思路:

  这道题让我们找缺失的首个正数，由于限定了 O(n) 的时间，所以一般的排序方法都不能用，不考虑空间复杂度的话，这个思路很简单，利用哈希表求解，把所有的数都存入 HashSet 中，然后循环从1开始递增找数字，哪个数字找不到就返回哪个数字，如果一直找到了最大的数字（这里是 nums 数组的长度），则加1后返回结果 res。
  
  但是利用哈希表的解法不是 O(1) 的空间复杂度，所以需要另想一种解法，既然不能建立新的数组，那么只能覆盖原有数组，思路是把1放在数组第一个位置 ``nums[0]``，2放在第二个位置 ``nums[1]``，即需要把 ``nums[i]`` 放在 ``nums[nums[i] - 1]``上，遍历整个数组，如果 ``nums[i] != i + 1``, 而 ``nums[i]`` 为整数且不大于n，另外 ``nums[i]`` 不等于 ``nums[nums[i] - 1]`` 的话，将两者位置调换，如果不满足上述条件直接跳过，最后再遍历一遍数组，如果对应位置上的数不正确则返回正确的数，这个思路与剑指Offer中的第三题**数组中重复的数字**方法类似
  

# 时间复杂度：
  O(n)
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Trapping-Rain-Water.cpp):
### 方法一： HashSet法
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if (n==0) return 0;
        long int max_value = *max_element(height.begin(),height.end());//找到vector数组中的最大值
        for (long int i =1;i<=max_value;i++)
        {
            bool flag = false;  //标记是否开始更新 temp
            int temp = 0;
            for (int j=0;j<n;j++)
            {
                if (flag && height[j] < i)
                {
                    temp++;
                }
                if (height[j]>=i)
                {
                    res += temp;
                    temp = 0;
                    flag = true;
                }
            }
        }
        return res;
    }
};
```
### 方法二： 交换位置法（与剑指Offer中的数组中重复的数字方法类似）
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            while(nums[i]<=n && nums[i]>0 && nums[i]!=nums[nums[i]-1])
            {
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
                // swap(nums[i],nums[nums[i]-1]);
            }
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=i+1)
              return i+1;
        }
        return n+1;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Trapping-Rain-Water/Trapping-Rain-Water.py)
### 方法一： HashSet法
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n =len(nums)
        res = 1
        record = {}
        for index, num in enumerate (nums):
            record[num] = index
        for i in range (n):
            if res not in record:
                return res
            else:
                res+=1
        return res
```

### 方法二：交换位置法
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while nums[i]<=n and nums[i]>0 and nums[i]!=nums[nums[i]-1]:
                temp = nums[i]
                nums[i] = nums[temp-1]
                nums[temp-1] = temp
        for i in range(n):
            if nums[i]!=i+1:
                return i+1
        return n+1
```
# 参考
  - [C++中map，hash_map,unordered_map,unordered_set区别与联系](https://blog.csdn.net/u013195320/article/details/23046305)
  - [数组中重复的数字](https://github.com/bryceustc/CodingInterviews/blob/master/DuplicationInArray/README.md)
