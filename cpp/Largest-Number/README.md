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
###  Python 2 自定义排序法 方法一：
```python
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        res = ""
        n = len(nums)
        nums = sorted(nums, cmp=self.compare,reverse=True)
        # sorted 语法：
        # sorted(iterable, cmp=None, key=None, reverse=False)
        # 参数说明：
        # iterable -- 可迭代对象。
        # cmp -- 比较的函数，这个具有两个参数，参数的值都是从可迭代对象中取出，此函数必须遵守的规则为，大于则返回1，小于则返回-1，        等于则返回0。
        # key -- 主要是用来进行比较的元素，只有一个参数，具体的函数的参数就是取自于可迭代对象中，指定可迭代对象中的一个元素来进行         排序。
        # reverse -- 排序规则，reverse = True 降序 ， reverse = False 升序（默认）。
        for i in range(n):
            res+=str(nums[i])
        if res[0]=='0':
            return "0"
        else:
            return res
    def compare(self,a,b):
        sa = str(a)
        sb = str(b)
        if sa + sb > sb + sa:
            return 1
        return -1
```

### Python 2 自定义排序 方法二：
```python
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums:
            return ""
        # 直接拼接数字，可能导致数值溢出，这是一个隐形的大数问题，需要把数字转换成字符串
        nums = map(str, nums)
        # 把数字m和n拼接为mn，nm，只需要按照字符串大小的比较
        nums.sort(lambda x, y: cmp(y + x, x + y))
        return ''.join(nums).lstrip('0') or '0'
```


### Python 3 自定义排序 方法一：
```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        res = ""
        n = len(nums)
        # nums = sorted(nums, cmp=self.compare) ## Python 3 没有cmp这个参数
        for i in range (n-1):
            for j in range (i+1,n):
                if int(str(nums[i])+str(nums[j])) < int (str(nums[j])+str(nums[i])):
                    nums[i],nums[j] = nums[j],nums[i]
        for i in range(n):
            res+=str(nums[i])
        if res[0]=='0':
            return "0"
        else:
            return res
```

### Python 3 自定义排序 方法二：
```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        if not nums:
            return ''
        nums = map(str, nums)
        key = cmp_to_key(lambda x, y: int(y + x) - int(x + y))
        # lstrip() 方法: 截掉字符串左边的空格或指定字符  0012->12
        res = ''.join(sorted(nums, key=key)).lstrip('0')
        # 000->''
        return res or '0'
```


# 参考
  - [剑指offer第45题-把数组排成最小的数](https://github.com/bryceustc/CodingInterviews/blob/master/MoreThanHalfNumber/README.md)
  - [C++中 string对象的大小比较](https://blog.csdn.net/jason_cuijiahui/article/details/79038468)
  - [C++ algorithm sort自定义排序](https://blog.csdn.net/v_xchen_v/article/details/76615270)
  - [关于类中重载sort函数的报错问题（解决error: invalid use of non-static member function 'bool Solution::cmp(int, int)'）](https://blog.csdn.net/qq_41562704/article/details/95908736)
  - [python3与python2的不同定义排序](https://leetcode-cn.com/problems/largest-number/solution/python3yu-python2de-bu-tong-ding-yi-pai-xu-by-jixi/)
  - [Python3: 找回sort()中消失的cmp参数](https://www.polarxiong.com/archives/Python3-%E6%89%BE%E5%9B%9Esort-%E4%B8%AD%E6%B6%88%E5%A4%B1%E7%9A%84cmp%E5%8F%82%E6%95%B0.html)
  - [Python map函数用法](https://www.runoob.com/python/python-func-map.html)



