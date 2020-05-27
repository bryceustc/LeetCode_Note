```c++
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
    }
};

/*

A = [4,5,0,-2,-3,1]

循环A
i = 0,  preSum = (0 + 4) % 5 = 4, map中不存在4 => map[4] = 1
i = 1,  preSum = (4 + 5) % 5 = 4, map中存在4 => count += map[4] => count = 1,  map[4] = map[4] + 1 = 2
i = 2,  preSum = (4 + 0) % 5 = 4, map中存在4 => count += map[4] => count = 3,  map[4] = 3
i = 3,  preSum = (4 - 2) % 5 = 2, map中不存在2 => map[2] = 1
i = 4,  preSum = (2 - 3) % 5 = -1 小于0 => preSum = -1 + 5 = 4, map中存在4 => count += map[4] => count = 6,  map[4] = 4
i = 5,  preSum = (4 + 1) % 5 = 0, map中存在0 => count += map[0] => count = 7, map[0] = 2
*/
```
