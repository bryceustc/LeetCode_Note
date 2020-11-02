```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        vector<int> res;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
```

```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int,int> mp;
        for (int num : nums1) {
            mp[num]++;
        }
        vector<int> res;
        for (int &num : nums2) {
            if(mp.count(num)) {
                res.push_back(num);
                mp[num]--;
                if (mp[num] == 0) {
                    mp.erase(num);
                }
            }
        }
        return res;
    }
};
```
