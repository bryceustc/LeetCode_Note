# 题目描述:  最长连续序列

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。


**示例 1:**
```
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
```
  
# 解题思路:
利用哈希表
# 时间复杂度：
  方法一：O(nlogn)
  方法二：O(logn)
# 空间复杂度
  方法一和方法二都为O(n)
  
# 代码

### 方法一： 第一次做法，注意set的底层是红黑树，插入操作是logn
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 1;
        int k = 1;
        int n = nums.size();
        if (n==0) return 0;
        set<int> s;
        for (int &a : nums){
            s.insert(a);
        }
        // s.insert(nums.begin(),nums.end());
        
        vector<int> v(s.begin(),s.end());
        int tmp = v[0];
        for (int i=1;i<v.size();i++){
            if (v[i]-tmp==1){
                k++;
            }
            else{
                k = 1;
            }
            res = max(res,k);
            tmp = v[i];
        }
        return res;
    }
};
```

### 方法二：unordered_set
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res =1;
        unordered_set<int> s;
        s.insert(nums.begin(),nums.end());
        for (int &num : nums){
            // 不存在num-1，就重新计数
            if (!s.count(num-1)){
                int count =1;
                while(s.count(num+1)){
                    num+=1;
                    count++;
                }
                res = max(res,count);
            }
        }
        return res;
    }
};
```
