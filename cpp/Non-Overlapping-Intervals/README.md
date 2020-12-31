### 435. 无重叠区间

给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例：
输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。

贪心策略
```c++
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];//以右边界进行排序
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int num = 1;
        int end = intervals[0][1];    
        for(int i = 1; i < n; i++){
            if(intervals[i][0]>=end){//找到与前一个不交叉&&右边界最小的
                end = intervals[i][1];
                num++;
            }
        }
        return n-num;
    }
};
```
