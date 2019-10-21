class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v(nums1.begin(), nums1.end());
    for (auto& e : nums2) {
        v.push_back(e);
    }
    sort(v.begin(), v.end());
    float n1;
    if (v.size() % 2 == 0) {
        //int i = v.size() / 2;
        int j = v[v.size() / 2];
        int k = v[v.size() / 2-1];
        n1 = (j+k) / 2.0;
    }
    else {
        n1 = v[v.size() / 2];
    }
    return n1;
    }

  };
