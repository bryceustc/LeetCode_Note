# 题目描述:  最大数

给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

**示例 1:**
```
输入: [10,2]
输出: 210
```

**示例 2:**
```
输入: [3,30,34,5,9]
输出: 9534330
```
**说明:** 
输出结果可能非常大，所以你需要返回一个字符串而不是整数。
  
# 解题思路:
此题与剑指offer第45题类似
这道题给了我们一个数组，让将其拼接成最大的数，那么根据题目中给的例子来看，主要就是要给数组进行排序，但是排序方法不是普通的升序或者降序，因为9要排在最前面，而9既不是数组中最大的也不是最小的，所以要自定义排序方法。如果不参考网友的解法，博主估计是无法想出来的。这种解法对于两个数字a和b来说，如果将其都转为字符串，如果 ab > ba，则a排在前面，比如9和34，由于 934>349，所以9排在前面，再比如说 30 和3，由于 303<330，所以3排在 30 的前面。按照这种规则对原数组进行排序后，将每个数字转化为字符串再连接起来就是最终结果。

 
# 时间复杂度：
  时间复杂度：O(nlogn)
  尽管我们在比较函数中做了一些额外的工作，但是这只是一个常数因子。所以总的时间复杂度是由排序决定的，在 C++ 和 Python 中都是 O(nlogn)。
# 空间复杂度
  O(n)
  这里，我们使用了 O(n) 的额外空间去保存 nums 的副本。尽管我们就地进行了一些额外的工作，但最后返回的数组需要 O(n) 的空间。因此，需要的额外空间与 nums 大小成线性关系。
# 代码

## [C++](./Largest-Number.cpp):

###  自定义Sort比较法
```c++
class Solution{
    public:
        string largestNumber(vector<int>& nums)
        {
            string res;
            int n = nums.size();
            sort(nums.begin(),nums.end(),compare);  // compare 自定义比较规则，不设置默认是从小到大
            for (int i=0;i<n;i++)
            {
                res += to_string(nums[i]);
            }
            if (res[0] == '0') 
                return "0";
            else
                return res;          
        }
        // 需要加static
        // 原因：
        // 简单来讲，就是函数参数不匹配的问题。因为我们普通的成员函数都有一个隐含的this指针。
        // bool cmp( Solution* this, const Interval &a,const Interval &b );
        // 实际上cmp函数有三个参数，而我们调用sort()排序函数的时候只需要用到两个参数进行比较，所以就出现了形参与实参不匹配的情况
        //（函数有三个形参，但是只输入了两个实参）。
        static bool compare(int a, int b)
        {
            string sa = to_string(a);
            string sb = to_string(b);
            return (sa + sb) > (sb + sa);
            // 两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇’\0’为止。
            // 当两个数的位数一样，则直接可以应用字符串的比较。如 "1346" > "1111" == true
        }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Largest-Number/Largest-Number.py)
###  方法一：暴力法
```python
class Solution:
    def majorityElement(self, nums):
        # write code here
        res = 0
        n = len(nums)
        half = n//2
        if n==0:
            return res
        for i in range(n):
            cnt = 0
            for num in nums:
                if nums[i] == num:
                    cnt+=1
            if cnt > half:
                res = nums[i]
        return res
```
### 方法二 ： 摩尔投票法
```python
class Solution:
    def majorityElement(self, nums):
        # write code here
        res = nums[0]
        cnt = 0
        n = len(nums)
        half = n//2
        if n==0:
            return 0
        for i in range(1,n):
            if cnt == 0:
                res = nums[i]
            if res == nums[i]:
                cnt+=1
            else:
                cnt-=1
        m = 0
        for num in nums:
            if (res == num):
                m+=1
        if m<=half:
            res = 0
        return res
```

### 方法三 ： 排序法
```python
class Solution:
    def majorityElement(self, nums):
        # write code here
        res = 0
        n = len(nums)
        nums=sorted(nums)
        res = nums[n//2]
        return res
```



# 参考
  - [剑指offer第39题-数组中出现次数超过一半的数字](https://github.com/bryceustc/CodingInterviews/blob/master/MoreThanHalfNumber/README.md)
  - [C++中 string对象的大小比较](https://blog.csdn.net/jason_cuijiahui/article/details/79038468)
  - [C++ algorithm sort自定义排序](https://blog.csdn.net/v_xchen_v/article/details/76615270)
  - [关于类中重载sort函数的报错问题（解决error: invalid use of non-static member function 'bool Solution::cmp(int, int)'）](https://blog.csdn.net/qq_41562704/article/details/95908736)



