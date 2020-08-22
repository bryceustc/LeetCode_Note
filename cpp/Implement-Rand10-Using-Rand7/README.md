### 题目描述 用 Rand7() 实现 Rand10()

已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

不要使用系统的 Math.random() 方法。

示例1：
```
输入: 1
输出: [7]
```

示例2 ：
```
输入: 2
输出: [8,4]

输入: 3
输出: [8,1,10]
```

### 思路

已知 rand_N() 可以等概率的生成[1, N]范围的随机数

那么：

(rand_X() - 1) × Y + rand_Y() ==> 可以等概率的生成[1, X * Y]范围的随机数

即实现了 rand_XY()

### 代码

```c++
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x = 0;
        while(true) {
            x = (rand7() - 1) * 7 + rand7();  // 等概率生成[1,49]范围的随机数
            if (x <= 40) {
                break;  // 拒绝采样，并返回[1,10]范围的随机数
            }
        }
        return x % 10 + 1;
    }
}
```

优化版
```c++
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true) {
            int a = rand7();
            int b = rand7();
            int num = (a-1)*7 + b; // rand 49
            if(num <= 40) return num % 10 + 1; // 拒绝采样
            
            a = num - 40; // rand 9
            b = rand7();
            num = (a-1)*7 + b; // rand 63
            if(num <= 60) return num % 10 + 1;
            
            a = num - 60; // rand 3
            b = rand7();
            num = (a-1)*7 + b; // rand 21
            if(num <= 20) return num % 10 + 1;
        }
    }
};
```
