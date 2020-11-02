```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n = nums2.size();
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> st;
        for (int &num : nums2) {
            if (s.count(num) && !st.count(num)) {
                res.push_back(num);
                st.insert(num);
            }
        }
        return res;
    }
};
```
