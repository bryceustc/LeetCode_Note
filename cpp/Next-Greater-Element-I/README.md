# 题目描述:  下一个更大元素 I

给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

**示例 :**
```
输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
```
# 解题思路:
  哈希表+单调栈
  
# 代码

###  哈希表+直接暴力
```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        unordered_map<int,int> m;
        for (int i=0;i<n2;i++)
        {
            m[nums2[i]] = i;
        }
        for(int j=0;j<n1;j++)
        {
            int i = m[nums1[j]];
            int k = 0;
            for (k=i;k<n2;k++)
            {
                if (nums2[k] > nums1[j])
                {
                    res.push_back(nums2[k]);
                    break;
                }
            }
            if (k==n2) res.push_back(-1);
        }
        return res;
    }
};
```
### 哈希表+单调栈
```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> s;
        unordered_map<int,int> m;
        int i =0;
        while(i<n2)
        {
            //  注意 这次栈里存的不是坐标
            if (s.empty() || nums2[i] < s.top())
            {
                s.push(nums2[i++]);
            }
            else
            {
                int t = s.top();
                s.pop();
                m[t] = nums2[i];
            }
        }
        for (int num : nums1)
        {
            if (m.count(num)==1)
            {
                res.push_back(m[num]);
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
    }
};
```
