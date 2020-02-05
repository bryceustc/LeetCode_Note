# 题目描述:  反转链表

反转一个单链表。

**示例 :**
```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```
**进阶:** 
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
  
# 解题思路:
此题与剑指offer第6题从尾到头打印链表类似

有两种方法：

方法一：非递归方法，利用两个结点指针和一个中间结点指针temp(用来记录当前结点的下一个节点的位置)，分别指向当前结点和前一个结点，每次循环让当前结点的指针域指向前一个结点即可，翻转结束后，记得将最后一个节点的链域置为空。

方法二：递归方法

 
# 时间复杂度：
  假设 n 是列表的长度，时间复杂度是 O(n)。
# 空间复杂度
  方法一：O(1)
  
  方法二：O(n),由于使用递归，将会使用隐式栈空间。递归深度可能会达到 n 层。
# 代码

## [C++](./Reverse-Linked-List.cpp):

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

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Reverse-Linked-List/Reverse-Linked-List.py)
###  方法一：
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

### 方法二：
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
# 参考
  - [剑指offer第6题-从尾到头打印链表](https://github.com/bryceustc/CodingInterviews/blob/master/PrintListInReversedOrder/README.md)
  - [C++中 string对象的大小比较](https://blog.csdn.net/jason_cuijiahui/article/details/79038468)
  - [C++ algorithm sort自定义排序](https://blog.csdn.net/v_xchen_v/article/details/76615270)
  - [关于类中重载sort函数的报错问题（解决error: invalid use of non-static member function 'bool Solution::cmp(int, int)'）](https://blog.csdn.net/qq_41562704/article/details/95908736)
  - [python3与python2的不同定义排序](https://leetcode-cn.com/problems/largest-number/solution/python3yu-python2de-bu-tong-ding-yi-pai-xu-by-jixi/)
  - [Python3: 找回sort()中消失的cmp参数](https://www.polarxiong.com/archives/Python3-%E6%89%BE%E5%9B%9Esort-%E4%B8%AD%E6%B6%88%E5%A4%B1%E7%9A%84cmp%E5%8F%82%E6%95%B0.html)
  - [Python map()函数用法](https://www.runoob.com/python/python-func-map.html)
  - [Python sorted()函数用法](https://www.runoob.com/python/python-func-sorted.html) 




