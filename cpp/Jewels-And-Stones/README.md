```c++
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_map<char,int> m;
        for (char &c : S) {
            m[c]++;
        }
        for (char &c : J) {
            res += m[c];
        }
        return res;
    }
};
```
