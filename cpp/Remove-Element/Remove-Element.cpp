/// Source : https://leetcode-cn.com/problems/remove-element/
/// Author : bryce
/// Time   : 2019-11-18

/*
思路：
1. 如果nums为空，直接返回0
2. 初始化k = 0,从i=0开始遍历整个数组，如果nums[i]不等于val，说明是有效元素，令nums[k] = nums[i]，并令k++
3. 返回res = k

时间复杂度：
遍历一遍数组，时间复杂度为O(n)

空间复杂度：
仅定义了两个临时变量，故空间复杂度是O(1)。
*/
// C++ Solution 1:(for循环)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        if (nums.empty()) return res;
        int n = nums.size();
        int k = 0;
        for (int i = 0; i<n; i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        res = k;
        return res;
    }
};


/*
思路：
1. 如果nums为空，直接返回0
2. 初始化左右两个指针指向数组初始,如果右指针指向元素等于val,则继续向后移动右指针
3. 不相等，则为有效元素令nums[l] = nums[r],然后左右两个指针同时向后移动
4. 当右指针走完整个数组后，左指针当前的坐标就是res
*/



// C++ Solution 2:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        if (nums.empty()) return res;
        int n = nums.size();
        int l = 0, r = 0;
        while (r<n)
        {
            if (nums[r] == val)
            {
                r++;
            }
            else
            {
                nums[l] = nums[r];
                l++;
                r++;
            }
        }
        res = l;
        return res;
    }
};
