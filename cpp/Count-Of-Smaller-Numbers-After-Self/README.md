```c++
// 使用归并排序 计算逆序对
class Solution {
public:
    vector<int> res;
    vector<pair<int,int>> temp;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return {};
        res = vector<int> (n,0);
        vector<pair<int,int>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({nums[i],i});
        }
        temp = vector<pair<int,int>> (n, {0,0});
        merge_sort(v, 0, n-1);
        return res;
    }
    void merge_sort(vector<pair<int,int>>&nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            merge_sort(nums, left, mid);
            merge_sort(nums, mid+1, right);
            merge(nums,left, right);
        }
    }
    void merge(vector<pair<int,int>>&nums, int left, int right) {
        int mid = left + (right - left) / 2;
        int i = 0;
        int l = left;
        int r = mid + 1;
        while (l <= mid && r <= right) {
            if (nums[l].first <= nums[r].first) {
                res[nums[l].second] += r - (mid + 1);
                temp[i++] = nums[l++];
            } else {
                temp[i++] = nums[r++];
            }
        }
        while (l <= mid) {
            res[nums[l].second] += r - mid - 1;
            temp[i++] = nums[l++];
        }
        while (r <= right) {
            temp[i++] = nums[r++];
        }
        i=0;
        while (left<=right) {
            nums[left++] = temp[i++];
        }
    }
};
```
