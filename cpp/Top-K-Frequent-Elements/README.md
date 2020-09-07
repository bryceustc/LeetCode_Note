## 前 K 个高频元素

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例1：
```
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```


前k大，用小顶堆，前k小用大顶堆
```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        unordered_map<int, int> m;
        for (int num : nums) m[num]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for (auto p : m) {
            heap.push({p.second, p.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        while(!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
