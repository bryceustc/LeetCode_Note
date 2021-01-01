#### 种花问题
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

```
输入: flowerbed = [1,0,0,0,1], n = 1
输出: True

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
```


### 思路：
在 flowerbed 数组两端各增加一个 0， 这样处理的好处在于不用考虑边界条件，任意位置处只要连续出现三个 0 就可以栽上一棵花。
```c++
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> tmp;
        tmp.push_back(0);
        for(int a : flowerbed){
            tmp.push_back(a);
        }
        tmp.push_back(0);
        int res = 0;
        for (int i=1;i<tmp.size()-1;i++){
            if (tmp[i]!=1&&tmp[i-1]!=1&&tmp[i+1]!=1){
                tmp[i]=1;
                res++;
            }
        }
        return res>=n;
    }
};
```
