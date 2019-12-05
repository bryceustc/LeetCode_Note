/// Source : https://leetcode-cn.com/problems/trapping-rain-water/
/// Author : bryce
/// Time   : 2019-12-3

// C++ Solution 1:
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.empty()) return res;
        int n = height.size();
        //因为两端不可能积雨水，下标从1到n-2
        for (int i =1; i<n-1; i++)
        {
            int max_left = 0;
            int max_right = 0;
            
            // 寻找左边最高
            for (int j = i-1;j>=0;j--)
            {
                if (height[j]>max_left)
                {
                    max_left = height[j];
                }
            }
            
            // 寻找右边最高
            for (int k =i+1;k<n;k++)
            {
                if (height[k] > max_right)
                {
                    max_right = height[k];
                }
            }
            
            int min_height = min(max_left,max_right);
            if ( min_height > height[i])
            {
                res += min_height - height[i];
            }
        }
        return res;
    }
};


// C++ Solution 2:
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.empty()) return res;
        int n = height.size();
        vector<int> max_left(n,0);
        vector<int> max_right(n,0);
        for (int i = 1;i<n-1;i++)
        {
            max_left[i] = max(max_left[i-1],height[i-1]);
        }
        for (int i = n-2;i>=0;i--)
        {
            max_right[i] = max(max_right[i+1],height[i+1]);
        }
        
        for (int i=1;i<n-1;i++)
        {
            int min_height = min(max_left[i],max_right[i]);
            if (min_height > height[i])
                res += min_height-height[i];
        }
        return res;
    }
};

// C++ Solution 3:
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int left = 1,right=n-2;
        int max_left=0,max_right=0;
        while (left <= right)
        {
          if (height[left-1] < height[right+1])
          {
              max_left = max(max_left,height[left-1]);
              int min_height = max_left;
              if (min_height > height[left])
                  res += min_height - height[left];
              left++;
          }
          else
          {
              max_right = max(max_right,height[right+1]);
              int min_height = max_right;
              if (min_height > height[right])
                  res += min_height - height[right];
              right--;
          }
        }
        return res;
    }
};

// C++ Solution 4:
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int left = 1,right=n-2;
        int max_left=0,max_right=0;
        while (left <= right)
        {
          if (height[left-1] < height[right+1])
          {
              max_left = max(max_left,height[left-1]);
              int min_height = max_left;
              if (min_height > height[left])
                  res += min_height - height[left];
              left++;
          }
          else
          {
              max_right = max(max_right,height[right+1]);
              int min_height = max_right;
              if (min_height > height[right])
                  res += min_height - height[right];
              right--;
          }
        }
        return res;
    }
};
