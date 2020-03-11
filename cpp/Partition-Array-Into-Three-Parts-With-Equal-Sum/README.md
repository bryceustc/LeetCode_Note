# 题目描述:  将数组分成和相等的三个部分

给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。


**示例 :**
```
输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
```
**示例 :**
```
输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
```

# 解题思路:
  注意这个trick，三等分值

  1. 双指针 
  
  2. 直接法
# 时间复杂度：
  O(N)
# 空间复杂度
  O(1)
  
# 代码

## C++
### 双指针法
```c++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        for (int a: A)
        {
            sum+=a;
        }
        // 总和不是3的倍数，直接返回false
        if (sum%3!=0) 
            return false;
        int avg = sum/3;
        // 使用双指针,从数组两头开始一起找，节约时间
        int l = 0;
        int r = n-1;
        // 不能初始化为0，因为有可能sum和为0
        int left_sum = A[l]; 
        int right_sum = A[r];
        // 使用left + 1 < right 的原因，防止只能将数组分成两个部分
        // 例如：[1,-1,1,-1]，使用left < right作为判断条件就会出错
        while (l+1<r)
        {
            // 先判断,因为初始化为A[l]和A[r]了
            if (left_sum==avg && right_sum==avg)
            {
                // 左右两边都等于 avg ，中间也一定等于
                return true;
            }
            if (left_sum!=avg)
            {
                // left = 0赋予了初值，应该先left++，在leftSum += A[left];
                left_sum+=A[++l];
            }
            if (right_sum!=avg)
            {
                // right = n-1赋予了初值，应该先right--，在rightSum += A[right];
                right_sum+=A[--r];
            }
        }
        return false;
    }
};
```
###  直接寻找法
```c++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        for (int a: A)
        {
            sum+=a;
        }
        if (sum%3!=0)
        {
            return false;
        }
        int avg = sum/3;
        int s = 0;
        int count=0;
        for (int i:A)
        {
            s+=i;
            if(s==avg)
            {
                count++;
                s=0;
            }
            
        }
        return count>=3; 
        //按理说总和为 sum ，算sum / 3 的次数，普通情况肯定为3，超过3次的情况，sum必定为0。n堆0，都能分为3堆0。（n > 3）
    }
};
```
