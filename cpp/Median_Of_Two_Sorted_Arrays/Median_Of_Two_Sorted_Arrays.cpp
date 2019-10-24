/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/// Author : bryce
/// Time   : 2019-10-24

//原始方法：合并数组求中位数 二分法查找（并不满足时间复杂度要求）
class Solution1 {
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

//
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n + m + 1)/2;
        int right = (n + m + 2)/2;
        //一个小技巧将偶数和奇数进行合并，如果是奇数会求两次同样的k
        double res_l = find_Kth_num(nums1, 0, n-1 ,nums2, 0, m - 1, left);
        double res_r = find_Kth_num(nums1, 0, n-1 ,nums2, 0, m - 1, right);
        double  res = (res_l + res_r)/2;
        return res;
    }
    double find_Kth_num(vector<int>& nums1, int start1, int end1, vector<int>&nums2, int start2, int end2, int k){
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        //让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
        if(len1 > len2) return find_Kth_num(nums2, start2, end2, nums1, start1, end1, k);
        if(len1 == 0) return nums2[start2 + k -1];
        
        if (k == 1) return min(nums1[start1], nums2[start2]);
        
        int i = start1 + min(len1, k/2) - 1;
        int j = start2 + min(len2, k/2) - 1;
        if (nums1[i] > nums2[j])
        {
            return find_Kth_num(nums1, start1, end1, nums2, j+1, end2, k - (j - start2 + 1) );
        }
        else
        {
            return find_Kth_num(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));     
        }
    }
};
