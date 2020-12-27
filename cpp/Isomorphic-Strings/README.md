```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (n == 0) return true;
        int i = 0;
        while (i < n) {
            if (s.find(s[i]) != t.find(t[i])) {
                return false;
            }
            i++;
        }
        return true;
    }
};
```
