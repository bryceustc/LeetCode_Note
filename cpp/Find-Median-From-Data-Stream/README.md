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
此题与剑指Offer第41题相同

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
###  方法一：直接排序法（未通过OJ，时间超时 )
```python
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.store=[] 

    def addNum(self, num: int) -> None:
        self.store.append(num)

    def findMedian(self) -> float:
        store=sorted(self.store)
        n = len(self.store)
        if n%2==0:
            return (self.store[n//2]+self.store[n//2-1])/2.0
        else:
            return self.store[n//2]
        

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```
### 方法二 ：插入排序(未通过OJ，时间超时)
```python
class MedianFinder:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.store=[] 
    
    def insertSort(self,arr):
        for i in range(1,len(arr)):
            j = i-1
            key = arr[i]
            while j >= 0:
                if arr[j] > key:
                    arr[j+1] = arr[j]
                    arr[j] = key
                j -= 1
        return arr
    
    def addNum(self, num: int) -> None:
        self.store.append(num)
        self.store = self.insertSort(self.store)

    def findMedian(self) -> float:
        n = len(self.store)
        if n%2==0:
            return (self.store[n//2]+self.store[n//2-1])/2.0
        else:
            return self.store[n//2]
        

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```

### 方法三 ：利用python自带的heapq库实现大小堆求解
```python
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.count = 0
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        # 因为 Python 中的堆默认是小顶堆，所以要传入一个相反数，
        # 才能模拟出大顶堆的效果
        if self.count % 2 == 0:
            heapq.heappush(self.max_heap, -num)
            max_heap_top = heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap,-max_heap_top)
        else:
            heapq.heappush(self.min_heap, num)
            min_heap_top = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap,-min_heap_top)
        self.count+=1
    def findMedian(self) -> float:
        if self.count % 2 == 0:
            return (self.min_heap[0] - self.max_heap[0])/2.0
        else:
            return self.min_heap[0]      


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```



# 参考

  -  [剑指Offer_41题_数据流的中位数](https://github.com/bryceustc/CodingInterviews/blob/master/StreamMedian/README.md)
  -  [python数据结构堆（heapq）库使用](https://blog.csdn.net/brucewong0516/article/details/79042839)





