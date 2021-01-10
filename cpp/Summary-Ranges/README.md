### 汇总区间
给定一个无重复元素的有序整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：
```
"a->b" ，如果 a != b
"a" ，如果 a == b
```
示例1：
```
输入：nums = [0,1,2,4,5,7]
输出：["0->2","4->5","7"]
解释：区间范围是：
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```
### 思路
模拟法，给定数组是有序的，直接寻找到第一个不是连续递增+1的即可。
```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (i + 1 < n && nums[i+1] == nums[i] +1) {
                i++;
            }
            string a = to_string(nums[j]);
            string b = to_string(nums[i]);
            if (a != b) {
                string tmp = a + "->" + b;
                res.push_back(tmp);
            } else {
                res.push_back(a);
            }
        }
        return res;
    }
};
```
