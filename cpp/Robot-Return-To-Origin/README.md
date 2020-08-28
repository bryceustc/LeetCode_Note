

```c++
class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        if (n & 1) return false;
        unordered_map<char, int> m;
        for (char &c : moves) {
            m[c]++;
        }
        return m['L'] == m['R'] && m['U'] == m['D'];
     }
};
```
