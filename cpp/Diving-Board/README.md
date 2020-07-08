注意k=0和shorter==longer这两种特殊情况

最短: shorter * k

第二短: shorter * k + (longer - shorter) * 1

第三短: shorter * k + (longer - shorter) * 2

...

最长:shorter * k + (longer - shorter) * k

结束
```c++
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k==0) return {};
        if (shorter==longer) return {shorter*k};
        vector<int> res(k+1, 0);
        res[0] = shorter*k;
        for (int i = 1; i < k+1; ++i) {
            res[i] = res[i-1] + longer - shorter;
        }
        return res;
    }
};
```
