# 题目描述: 204. 计数质数

统计所有小于非负整数 n 的质数的数量。

**示例 1:**
```
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
```

**示例 2:**
```
输入：n = 0
输出：0
```
  
# 解题思路:
  
  此题首先想到的是暴力法，计数质数
  
  但其实可以用数学方法来求
  

# 时间复杂度：
  暴力法： $O(n \sqrt{n})$
  
  数学法：$ O(n \log \log n) $
  
# 代码
### 暴力
```c++
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(i)) res++;
        }
        return res;
    }
    bool isPrime(int n) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        if (n < 2) return false;
        return true;
    }
};
```
### 数学法
```c++
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<int> isPrime(n, 1);
        // 从二开始，0 和 1 都不算是质数
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res++;
                // 把i的倍数的数排除,比如i = 2, 4,6,8,10...都要排除
                for (int j = i + i; j < n; j+=i) {
                // 排除当前质数的倍数
                    isPrime[j] = 0;
                }
            }
        }
        return res;
    }
};
```
