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

  
  

# 时间复杂度：
  暴力遍历法：O(n<sup>2</sup>)
  
  
# 空间复杂度
  O(1)
  
# 代码

## [C++](./Trapping-Rain-Water.cpp):
### 方法一： 暴力遍历法：按行求
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.empty()) return res;
        int n = height.size();
        int max_value = *max_element(height.begin(),height.end());    //找到vector数组中的最大值
        for (int i=1;i<=max_value;i++)
        {
            bool flag = false;     //标记是否开始更新 temp
            int temp = 0;
            for (int j=0;j<n;j++)
            {
                if (flag && height[j] < i)   
                {
                    temp++;
                }
                if (height[j] >= i)
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


### 方法二： 暴力遍历法：按列求
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.empty()) return res;
        int n = height.size();
        //因为两端不可能积雨水，下标从1到n-2
        for (int i =1; i<n-1; i++)
        {
            int max_left = 0;
            int max_right = 0;
            
            寻找左边最高
            for (int j = i-1;j>=0;j--)
            {
                if (height[j]>max_left)
                {
                    max_left = height[j];
                }
            }
            
            // 寻找右边最高
            for (int k =i+1;k<n;k++)
            {
                if (height[k] > max_right)
                {
                    max_right = height[k];
                }
            }
            
            int min_height = min(max_left,max_right);
            if ( min_height > height[i])
            {
                res += min_height - height[i];
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
