# 题目描述:  数组中的第K个最大元素

在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

**示例 1:**
```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

**示例 2:**
```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

  
# 解题思路:
此题与剑指offer第40题类似

方法一：sort排序后返回，时间复杂度(nlogn)

方法二：大顶堆和小顶堆 时间复杂度(nlogk) 空间复杂度(logk)

方法三：Partition函数快速选择  时间复杂度(n)

 
# 时间复杂度：
  方法一：O(nlogn) 
  
  方法二：O(nlogk)
  
  方法三：O(n)

# 空间复杂度
方法一：O(1)

方法二：O(k)

方法三：O(1)
# 代码

## [C++](./Kth-Largest-Element-In-An-Array.cpp):

###  方法一： sort直接法
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        sort(nums.begin(),nums.end());
        res = nums[n-k];
        return res;        
    }
};
```

###  方法二： 小顶堆
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        priority_queue<int, vector<int>,greater<int>> q;
        for (auto num:nums)
        {
            q.push(num);
            if (q.size()>k)
            {
                q.pop();
            }
        }
        res = q.top();
        return res;        
    }
};
```

###  方法三： 利用Partition 函数
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        int start = 0;
        int end = n -1;
        int index = Partition(nums,start,end);
        while(index!=n-k)
        {
            if (index>n-k)
            {
                end = index - 1;
                index = Partition(nums,start,end);
            }
            else
            {
                start = index+1;
                index = Partition(nums,start,end);
            }
        }
        res = nums[n-k];
        return res;        
    }
    int Partition(vector<int> &nums,int start,int end){
        int pivot = nums[start];
        while (start < end)
        {
            while(start < end && nums[end]>=pivot)
            {
                end--;
            }
            nums[start] = nums[end];
            while(start < end && nums[start]<pivot)
            {
                start++;
            }
            nums[end] = nums[start];
        }
        nums[start] = pivot;
        return start;
    }
    
    int Partition (vector<int> &nums,int start,int end){
        int pivot = nums[start];
        int pos = start;
        for (int i=start+1;i<=end;i++)
        {
            if (nums[i]<pivot)
            {
                pos++;
                if (i!=pos)
                {
                    swap(nums[pos],nums[i]);
                }
            }
        }
        swap(nums[pos],nums[start]);
        return pos;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Kth-Largest-Element-In-An-Array/Kth-Largest-Element-In-An-Array.py)
###  方法一：sort 直接法
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        res = 0
        n = len(nums)
        if n==0 or k>n:
            return res
        nums = sorted(nums)
        res = nums[n-k]
        return res
```
### 方法二 ： 在 Python 的 heapq 库中有一个 nlargest 方法，具有同样的时间复杂度，能将代码简化到只有一行。
```python
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return heapq.nlargest(k, nums)[-1]
```

```python
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return heapq.nlargest(k, nums)[-1]
```



### 方法三 ： Partition 函数实现
```python
class Solution:
    def majorityElement(self, nums):
        # write code here
        res = 0
        n = len(nums)
        nums=sorted(nums)
        res = nums[n//2]
        return res
```



# 参考
  - [剑指offer第40题-最小的k个数](https://github.com/bryceustc/CodingInterviews/blob/master/KLeastNumbers/README.md)
  - [C/C++ | STL | 大顶堆 | 小顶堆 | std::priority_queue](https://blog.csdn.net/stone_fall/article/details/89010656) 
  - [【c++】STL里的priority_queue用法总结](https://blog.csdn.net/xiaoquantouer/article/details/52015928) 
  - [set/multiset用法详解](https://blog.csdn.net/longshengguoji/article/details/8546286) 
  - [std::set与std::multiset使用总结](https://blog.csdn.net/CV_Jason/article/details/83048406) 
  - [C++ multiset通过greater、less指定排序方式，实现最大堆、最小堆功能](https://www.cnblogs.com/ficow/p/10045777.html) 
  - [七种排序算法的C++与Python实现]()
  - [Partition函数的理解](https://github.com/bryceustc/CodingInterviews/blob/master/KLeastNumbers/Partition%E5%87%BD%E6%95%B0.md)


