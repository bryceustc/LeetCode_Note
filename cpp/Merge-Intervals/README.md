# 题目描述:  合并区间

给出一个区间的集合，请合并所有重叠的区间。

**示例 1:**
```
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

**示例 2:**
```
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

  
# 解题思路:
方法一：这次题目要求我们合并区间，首先要做的就是给区间集排序，由于我们要排序的是个结构体，所以我们要定义自己的 comparator，才能用 sort 来排序，我们以 start 的值从小到大来排序，排完序我们就可以开始合并了，首先把第一个区间存入结果中，然后从第二个开始遍历区间集，如果结果中最后一个区间和遍历的当前区间无重叠，直接将当前区间存入结果中，如果有重叠，将结果中最后一个区间的 end 值更新为结果中最后一个区间的 end 和当前 end 值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果

方法二：双指针，将起始位置和结束位置分别存到了两个不同的数组 starts 和 ends 中，然后分别进行排序，之后用两个指针i和j，初始化时分别指向 starts 和 ends 数组的首位置，然后如果i指向 starts 数组中的最后一个位置，或者当 starts 数组上 i+1 位置上的数字大于 ends 数组的i位置上的数时，此时说明区间已经不连续了，我们来看题目中的例子，排序后的 starts 和 ends 为：

starts:    1    <font color=Red>2</font>    8    15

ends:     <font color=Blue>3</font>    6    10    18

红色为i的位置，蓝色为j的位置，那么此时 starts[i+1] 为8，ends[i] 为6，8大于6，所以此时不连续了，将区间 [starts[j], ends[i]]，即 [1, 6] 加入结果 res 中，然后j赋值为 i+1 继续循环直至结束。

 
# 时间复杂度：
  O(nlogn) 
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Merge-Intervals.cpp):

###  方法一： 直接法
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res={intervals[0]};
        for (int i=1;i<n;i++)
        {
            if (res.back()[1]<intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};
```

#### 原地修改，空间复杂度为O(1)
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (!intervals.size()) return {};
        sort(intervals.begin(), intervals.end());
        int pos = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[pos][1] >= intervals[i][0]) 
            {
                intervals[pos][1] = max(intervals[pos][1], intervals[i][1]);
            } 
            else 
            {
                intervals[++pos] = intervals[i];
            }
        }
        intervals.resize(pos+1);
        return intervals;
    }
};
```


###  方法二： 双指针
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        nums.push_back({l,r}) ;
        sort(nums.begin(),nums.end()) ;                 //按左端点排序
        int st=-2e9,ed=-2e9 ;                           //ed代表区间结尾，st代表区间开头
        for(auto num:nums) {
                if(ed<num.first)  {                          //情况1：两个区间无法合并
                    if(ed!=-2e9) res.push_back({st,ed}) ;   //区间1放进res数组
                    st=num.first,ed=num.second ;            //维护区间2
                }
                //情况2：两个区间可以合并，且区间1不包含区间2，区间2不包含区间1
                else if(ed < num.second)  
                    ed = num.second ;                         //区间合并
            }  //(实际上也有情况3：区间1包含区间2，此时不需要任何操作，可以省略)
        
        if (st != -2e9) res.push_back({st, ed});
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Merge-Intervals/Merge-Intervals.py)
###  方法一：直接法
```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n=len(intervals)
        if n==0:
            return []
        intervals = sorted(intervals,key=lambda x:x[0])
        res = [intervals[0]]
        for i in range(1,n):
            if res[-1][1]<intervals[i][0]:
                res.append(intervals[i])
            else:
                res[-1][1]=max(res[-1][1],intervals[i][1])
        return res
```
### 方法二 ： 双指针
```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n=len(intervals)
        if n==0:
            return []
        res =[]
        starts=[]
        ends=[]
        for i in range(n):
            starts.append(intervals[i][0])
            ends.append(intervals[i][1])
        starts = sorted(starts)
        ends = sorted(ends)
        i=0
        j=0
        while i<n:
            if i==n-1 or starts[i+1]>ends[i]:
                res.append([starts[j],ends[i]])
                j=i+1
            i+=1
        return res
```


# 参考
  - [C++ sort 排序（降序、升序）使用总结](https://blog.csdn.net/zhangpiu/article/details/50564064)
