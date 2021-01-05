### 830. 较大分组的位置

在一个由小写字母构成的字符串 s 中，包含由一些连续的相同字符所构成的分组。

例如，在字符串 s = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。

分组可以用区间 [start, end] 表示，其中 start 和 end 分别表示该分组的起始和终止位置的下标。上例中的 "xxxx" 分组用区间表示为 [3,6] 。

我们称所有包含大于或等于三个连续字符的分组为 较大分组 。

找到每一个 较大分组 的区间，按起始位置下标递增顺序排序后，返回结果。

示例1：
```
输入：s = "abbxxxxzzy"
输出：[[3,6]]
解释："xxxx" 是一个起始于 3 且终止于 6 的较大分组。
```

```c++
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            char c = s[i];
            int j = i + 1;
            while (j < n && s[j] == c) {
                j++;
                count++;
            }
            if (count >= 3) {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(i + count - 1);
                res.push_back(tmp);
            }
            i = i + count - 1;
        }
        return res;
    }
};
```
