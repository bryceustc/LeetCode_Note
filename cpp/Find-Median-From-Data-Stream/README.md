# 题目描述:  数据流的中位数

中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：
  - void addNum(int num) - 从数据流中添加一个整数到数据结构中。
  - double findMedian() - 返回目前所有元素的中位数。

**示例 :**
```
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
```
**进阶 :**

1. 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？

2. 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

  
# 解题思路:
此题与LeetCode第295题相同

方法一：每插入一次就直接排序，然后根据存储数据的长度为奇数还偶数返回中位数，时间复杂度为O(nlogn)+O(1)

方法二：利用插入排序的思想，
方法三：利用大顶堆和小顶堆
 
# 时间复杂度：
  方法一： On)
  
  方法二： O(n<sup>2</sup>)
  
  方法三： O(n<sup>2</sup>) 
# 空间复杂度
  方法一：O(n)
  
  方法二：O(1)
  
  方法三：O(1)
  
# 代码

## [C++](./Find-Median-From-Data-Stream.cpp):

###  方法一： 直接排序：(未通过OJ，超时)
```c++
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> store;
    MedianFinder() {
        
    }
    void addNum(int num) {
        store.push_back(num);
    }
    
    double findMedian() {
        int n = store.size();
        sort(store.begin(),store.end());
        if (n%2==0)
        {
            return ((store[n/2]+store[n/2-1])/2.0);
        }
        else
        {
            return (store[n/2]);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

###  方法二： 插入排序
```c++
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> store;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if (store.empty())
        {
            store.push_back(num);
        }
        else
            store.insert(lower_bound(store.begin(),store.end(),num),num);
    }
    
    double findMedian() {
        int n = store.size();
        if (n%2==0)
        {
            return ((store[n/2]+store[n/2-1])/2.0);
        }
        else
        {
            return (store[n/2]);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

###  方法三： 大顶堆+小顶堆
```c++
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    int count=0;
    void addNum(int num) {
        if (count%2==0) // 偶数放入最大堆
        {
            max.push(num);
            int max_num = max.top();
            max.pop();
            min.push(max_num);
        }
        else     // 奇数放入最小堆
        {
            min.push(num);
            int min_num=min.top();
            min.pop();
            max.push(min_num);
        }
        count++;
    }
    
    double findMedian() {
        if (count%2==0)
        {
            return ((max.top()+min.top())/2.0);
        }
        else
        {
            return (min.top());
        }
        
    }
private:
    priority_queue<int,vector<int>> max;  //大顶堆
    priority_queue<int,vector<int>,greater<int>> min;  // 小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Find-Median-From-Data-Stream/Find-Median-From-Data-Stream.py)
###  方法一：构造辅助数组法（未通过OJ )
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        res = []
        n = len(nums)
        if n==0:
            return
        for i in range(n):
            if nums[i]!=0:
                res.append(nums[i])
        for i in range(n):
            if nums[i]==0:
                res.append(nums[i])
        nums=res
```
### 方法二 ：插入排序
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        for i in range(0,n):
            if nums[i]==0:
                for j in range(i+1,n):
                    if nums[j]!=0:
                        temp = nums[j]
                        for k in range (j,i,-1):
                            nums[k] = nums[k-1]
                        nums[i] = temp
                        break
```

### 方法三 ：冒泡排序(未通过OJ，超出时间限制)
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        for i in range(0,n):
                for j in range(n-1,i,-1):
                    if nums[j]!=0 and nums[j-1]==0:
                        temp = nums[j]
                        nums[j] = nums[j-1]
                        nums[j-1] = temp
```

### 方法四：python 自带函数
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(nums.count(0)):
            nums.remove(0)
            nums.append(0)
```
### 方法五：快指针扫描，满指针赋值记录，最后补0 (局部最优化)
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        j = 0
        for i in range(n):
            if nums[i]!=0:
                nums[j]=nums[i]
                j+=1
        for k in range(j,n):
            nums[k]=0
```

### 方法六：双指针扫描，最优化
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n==0:
            return
        i=0
        for j in range(0,n):
            if nums[j]!=0:
                nums[i],nums[j]=nums[j],nums[i]
                i+=1
```


# 参考

  -  [调整数组顺序使奇数位于偶数前面](https://github.com/bryceustc/CodingInterviews/blob/master/ReorderArray/README.md)





