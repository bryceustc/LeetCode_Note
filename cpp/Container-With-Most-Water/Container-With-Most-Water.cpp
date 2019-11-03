/// Source : https://leetcode-cn.com/problems/container-with-most-water/
/// Author : bryce
/// Time   : 2019-11-2

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
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
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int i, j = 0;
        if (n < 2) return 0;
        for (i = 0, j = n-1; i < j;)
        {
            int width = j - i;
            int high = min(height[i],height[j]);
            res = max(high * width, res);
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return res;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(height) << endl; // false
    return 0;
}
