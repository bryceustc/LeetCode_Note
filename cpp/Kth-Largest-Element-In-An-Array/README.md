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

方法二：O(logk)

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
        }
        return start;
    }
    
    int Partition (vector<int> &nums,int start,int end){
        int pivot = nums[start];
        int pos = start;
        fot (int i=start+1;i<=end;i++)
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


###  方法四：排序后返回 
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        if (nums.empty()) return res;
        int n = nums.size();
        int half = n/2;
        sort(nums.begin(),nums.end());
        res = nums[half];
        return res;      
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Kth-Largest-Element-In-An-Array/Kth-Largest-Element-In-An-Array.py)
###  方法一：暴力法
```python
class Solution:
    def majorityElement(self, nums):
        # write code here
        res = 0
        n = len(nums)
        half = n//2
        if n==0:
            return res
        for i in range(n):
            cnt = 0
            for num in nums:
                if nums[i] == num:
                    cnt+=1
            if cnt > half:
                res = nums[i]
        return res
```
### 方法二 ： 摩尔投票法
```python
class Solution:
    def majorityElement(self, nums):
        # write code here
        res = nums[0]
        cnt = 0
        n = len(nums)
        half = n//2
        if n==0:
            return 0
        for i in range(1,n):
            if cnt == 0:
                res = nums[i]
            if res == nums[i]:
                cnt+=1
            else:
                cnt-=1
        m = 0
        for num in nums:
            if (res == num):
                m+=1
        if m<=half:
            res = 0
        return res
```

### 方法三 ： 排序法
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


