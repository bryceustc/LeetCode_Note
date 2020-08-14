
猜数字游戏的规则如下：

每轮游戏，系统都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。

如果你猜错了，系统会告诉你这个数字比系统选出的数字是大了还是小了。

你可以通过调用一个预先定义好的接口 guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）

```c++
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (guess(mid) == 0) 
            {
                return mid;
            }
            else if (guess(mid) == 1) {
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }
        return 0;
    }
};
```
