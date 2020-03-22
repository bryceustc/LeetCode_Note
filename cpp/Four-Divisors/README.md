# 题目描述:  四因数

给你一个整数数组 nums，请你返回该数组中恰有四个因数的这些整数的各因数之和。

如果数组中不存在满足题意的整数，则返回 0 。


**示例 :**
```
输入：nums = [21,4,7]
输出：32
解释：
21 有 4 个因数：1, 3, 7, 21
4 有 3 个因数：1, 2, 4
7 有 2 个因数：1, 7
答案仅为 21 的所有因数的和。
```

# 解题思路:
  模拟法

# 时间复杂度：
  O(n×m)
# 空间复杂度
  O(1)

# 代码

### 
```c++
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            // cnt记录有多少个因子， out记录因子之和，针对每一个nums[i]都进行这样的操作
            int out = 0;
            int cnt = 0;
            // 任何一个数的因子都包括1和它本身
            for (int j=1; j*j<=nums[i]; j++)
            {
                if (nums[i]%j==0)
                {
                    // 求另一个因数
                    int x = nums[i]/j;
                    // 如果不相等
                    if (x!=j)
                    {
                        cnt+=2;
                        out += j + x;
                    }
                    // 相等则为同一个因数
                    else
                    {
                        cnt+=1;
                        out+=j;
                    }
                }
            }
            // 总共有四个因子的满足要求
            if (cnt==4)
                res += out;
        }
        return res;
    }
};
```
