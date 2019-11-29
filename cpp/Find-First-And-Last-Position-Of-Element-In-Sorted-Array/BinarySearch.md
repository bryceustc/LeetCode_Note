# 二分查找算法总结

二分查找法作为一种常见的查找方法，将原本是线性时间提升到了对数时间范围，大大缩短了搜索时间，具有很大的应用场景，而在 LeetCode 中，要运用二分搜索法来解的题目也有很多，但是实际上二分查找法的查找目标有很多种，而且在细节写法也有一些变化。我就对二分查找法的具体写法做个总结。

## 0. 二分查找的框架
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
