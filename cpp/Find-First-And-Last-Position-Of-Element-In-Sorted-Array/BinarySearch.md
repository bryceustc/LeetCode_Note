# 二分查找算法总结

二分查找法作为一种常见的查找方法，将原本是线性时间提升到了对数时间范围，大大缩短了搜索时间，具有很大的应用场景，而在 LeetCode 中，要运用二分搜索法来解的题目也有很多，但是实际上二分查找法的查找目标有很多种，而且在细节写法也有一些变化。我就对二分查找法的具体写法做个总结。

## 基础. 二分查找的框架
```c++
int binarySearch(vector<int> nums, int target) {
    int start = 0,end = ...;

    while(...) 
    {
        int mid =  start + (end - start) / 2;
        if (nums[mid] == target) 
        {
            ...
        } 
        else if (nums[mid] < target) 
        {
            left = ...
        } 
        else if (nums[mid] > target) 
        {
            right = ...
        }
    }
    return ...;
}
```
分析二分查找的一个技巧是：不要出现 else，而是把所有情况用 else if 写清楚，这样可以清楚地展现所有细节。本文都会使用 else if，旨在讲清楚，读者理解后可自行简化。

其中 ... 标记的部分，就是可能出现细节问题的地方，当你见到一个二分查找的代码时，首先注意这几个地方。后文用实例分析这些地方能有什么样的变化。

另外声明一下，计算 mid 时需要技巧防止溢出，即 mid=left+(right-left)/2。本文暂时忽略这个问题。

## 第一类：寻找一个数（基本的二分查找）
这是最简单的一类，也是我们最开始学二分查找法需要解决的问题,即搜索一个数，如果存在，返回其索引，否则返回 -1，比如我们有数组 [2, 4, 5, 6, 9]，target = 6，那么我们可以写出二分查找法的代码如下：
```c++
int binarySearch(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while (end>=start)
    {
      int mid = start + (end-start)/2;
      if (nums[mid]==target)
      {
        return mid;
      }
      
      else if (nums[mid]<target)
      {
        start = mid + 1;
      }
      else if (nums[mid]>target)
      {
        end = mid - 1;
      }
    }
    return -1;
}
```
**Q&A**
1. 为什么 while 循环的条件中是 <=，而不是 < ？

答：因为初始化 end 的赋值是 n-1，即最后一个元素的索引，而不是 n。
这二者可能出现在不同功能的二分查找中，区别是：前者相当于两端都闭区间 [start, end]，后者相当于左闭右开区间 [start, end)，因为索引大小为 n 是越界的。

我们这个算法中使用的是前者 [start, end] 两端都闭的区间。这个区间其实就是每次进行搜索的区间，我们称之为「搜索区间」。

什么时候应该停止搜索呢？当然，找到了目标值的时候可以终止：
```c++
    if(nums[mid] == target)
        return mid; 
```
但如果没找到，就需要 while 循环终止，然后返回 -1。那 while 循环什么时候应该终止？搜索区间为空的时候应该终止，意味着你没得找了，就等于没找到嘛。

while(left <= right) 的终止条件是 left == right + 1，写成区间的形式就是 [right + 1, right]，或者带个具体的数字进去 [3, 2]，可见这时候搜索区间为空，因为没有数字既大于等于 333 又小于等于 222 的吧。所以这时候 while 循环终止是正确的，直接返回 -1 即可。

while(left < right) 的终止条件是 left == right，写成区间的形式就是 [left, right]，或者带个具体的数字进去 [2, 2]，这时候搜索区间非空，还有一个数 222，但此时 while 循环终止了。也就是说这区间 [2, 2] 被漏掉了，索引 222 没有被搜索，如果这时候直接返回 -1 就是错误的。

2. 
