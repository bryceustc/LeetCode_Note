O(n)
```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (A[i]  <  A[i-1]){
                res = i -1;
                break;
            }
        }
        return res;
    }
};
```

O(logn)
```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int l = 0;
        int r = n -1;
        while (l < r) {
            int mid = l + (r-l + 1) / 2;
            if (A[mid] > A[mid-1]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
