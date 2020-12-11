# 题目描述: 842. 将数组拆分成斐波那契序列

给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。

**示例 1:**
```
输入："123456579"
输出：[123,456,579]
```

**示例 2:**
```
输入: "11235813"
输出: [1,1,2,3,5,8,13]

输入："0123"
输出：[]
解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。

输入: "1101111"
输出: [110, 1, 111]
解释: 输出 [11,0,11,11] 也同样被接受。
```
  
# 解题思路:
  
  dfs
  

# 时间复杂度：
  O(nlog^2C), 其中 n 是字符串的长度，C 是题目规定的整数范围 2^31−1
# 代码

### DFS递归法
```c++
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int>& list, string S, int length, int index, long long sum, int prev) {
        if (index == length) {
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++) {
            if (i > index && S[index] == '0') {
                break;
            }
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX) {
                break;
            }
            if (list.size() >= 2) {
                if (curr < sum) {
                    continue;
                }
                else if (curr > sum) {
                    break;
                }
            }
            list.push_back(curr);
            if (backtrack(list, S, length, i + 1, prev + curr, curr)) {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};
```
