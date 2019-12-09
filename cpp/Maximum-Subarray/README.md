# 题目描述:  最大子序和

给定一个整数数组 ``nums`` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。


**示例 :**
```
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

**进阶：**

  如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

  
# 解题思路:
  尝试一：暴力求解
  
  方法二：使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候我们再往回乘，如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。还有一点需要引起我们的注意的是n有可能为负数，对于n是负数的情况，我们可以先用其绝对值计算出一个结果再取其倒数即可。我们让i初始化为n，然后看i是否是2的倍数，是的话x乘以自己，否则res乘以x，i每次循环缩小一半，直到为0停止循环。最后看n的正负，如果为负，返回其倒数
# 时间复杂度：
  方法一：O(n<sup>2)
  方法二：O(n)
  方法三：O(nlogn)
# 空间复杂度
  方法一: O(1)
  方法二：O(n)
  方法三：O(1)
  
# 代码

## [C++](./Maximum-Subarray.cpp):

### 方法一： 暴力求解法
```c++
class Solution {
public:
    int maxSubArray(vector<int> &nums){
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int res = INT_MIN;
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            int sum = 0;
            for (int j=i;j<n;j++)
            {
                sum+=nums[j];
                res = max(res,sum);
            }
        }
        return res;
    }
};
```

### 方法二：折半计算
```c++
class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        for(int i=n;i!=0;i/=2)
        {
            if (i%2 != 0)
            {
                res*=x;
            }
            x*=x;
        }
        if (n<0)
          res = 1/res;
        return res;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Maximum-Subarray/Maximum-Subarray.py)
### 方法一： 暴力求解法
```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = x
        if x==0:
            return 0
        if x==1:
            return 1
        if x==-1 and n%2 == 0:
            return 1
        if x==-1 and n%2 != 0:
            return -1
        if n==2147483647 and x<1:
            return 0
        if n==-2147483648 and x>1:
            return 0
        if n>0:
            for i in range(1,n):
                res *= x
        if n<0:
            for i in range(-1,n,-1):
                res *=x
            res = 1/res
        if n==0:
            res = 1
        return res;
```

### 方法二： 折半计算
```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1.0
        i = abs(n)    ### 注意Python负数取余与C++负数取余不一样
        while i!=0:
            if i%2!=0:
                res*=x
            x*=x
            i=i//2
        if n<0:
            res = 1/res
        return res
```

