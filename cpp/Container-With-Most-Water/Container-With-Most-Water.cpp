/// Source : https://leetcode-cn.com/problems/container-with-most-water/
/// Author : bryce
/// Time   : 2019-11-2


//C++ Solution 1:
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int i, j = 0;
        if (n < 2) return 0;
        for (i = 0; i < n; i++)
        {
            for(j = i; j < n; j++)
            {
                int width = j - i;
                int high = min(height[i],height[j]);
                res = max(high * width, res);
            }
        }
        return res;
    }
};

// C++ Solution 2:
