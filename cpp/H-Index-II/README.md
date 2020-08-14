```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int i = 0; i <n ; i++){
            int h = n - i;
            if (citations[i] >= h) {
                return h;
            }
        }
        return 0;
    }
}
```



logn
```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0;
        int r = n -1;
        while (l <= r) {
            int mid = l + (r -l + 1) / 2;
            int h = n - mid;
            if (citations[mid] == h) {
                return h;
            } else if (citations[mid] < h) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return n - l;
    }
};
```
