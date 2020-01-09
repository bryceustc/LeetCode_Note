# 题目描述:  丑数II

编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的**正整数**。

**示例:**
```
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```


**说明：**
  1. ``1``是丑数
  2. 输入不会超过 32 位有符号整数的范围: [−2<sup>31</sup>,  2<sup>31</sup> − 1]。

  
# 解题思路:
此题与剑指offer第四十五题类似

方法一：想要判断一个数的因子是否为2,3,5只需要判断对这个几个数进行取模看是否能够整除然后再除以这几个数，直到最后为1即是丑数，不是1则不为丑数。然后从1开始按照顺序判断每一个数是不是丑数。**（时间复杂度很高未通过OJ）**

方法二：动态规划的思想,``dp[i]``表示第i个丑数，``dp[i]=Mymin(dp[l_2]*2,dp[l_3]*3,dp[l_5]*5)``,可以用i之前的所有丑数乘若干个2直到大于上一个丑数dp[i-1]，记此数为num1;同理用i之前的所有丑数乘若干个3直到大于上一个丑数dp[i-1]，记此数为num2；用i之前的所有丑数乘若干个5直到大于上一个丑数dp[i-1]，记此数为num3。这三个数中的最小数字就是第i个丑数dp[i]。

但是呢，其实没必要把i之前的所有丑数乘2或者乘3或者乘5。在i之前的丑数中，肯定存在一个丑数（下标记为index2），乘2以后正好大于i的上一个丑数dp[i-1],index2之前的丑数乘2都小于等于dp[i-1];我们只需要记录index2，每次直接用这个下标对应的数乘2就行，并且在下标不满足时更新下标。同理我们也要记录乘3和乘5对应的下标。

方法三：最小堆的思想，考虑到第n个丑数一定是由前面的丑数乘上2或3或5得到的，因此可以通过对每个丑数依次乘上2、3、5得到后面的丑数，在这里采用最小堆实现。维护一个最小堆，使得最小堆中的数一定是丑数。
首先初始化堆，将1放入堆中，之后循环n次，对于第i次，利用最小堆弹出最小的数，即第i大的丑数，然后对该数乘上2、3、5得到之后的丑数放入堆中，以此类推。

时间复杂度分析：每轮需要从堆中弹出堆顶并插入新的数，因此每一轮复杂度为O(logn)O(logn)，需要循环n轮，所以复杂度为O(nlogn)O(nlogn)。
 
# 时间复杂度：
  方法一：无法准确分析时间复杂度:至少O(n3)
  
  方法二：O(n)
  
  方法三：O(nlogn)
  
# 空间复杂度
  方法一:O(1)
  
  方法二:O(n)
  
  方法三:O(logn)
  
# 代码

## [C++](./Ugly-Number-II.cpp):

###  方法一：直接法
```c++
class Solution {
public:
    bool isUgly(int num) {
        if (num<1)
            return false;
        while(num%5==0)
        {
            num/=5;
        }
        while(num%3==0)
        {
            num/=3;
        }
        while(num%2==0)
        {
            num/=2;
        }
        return num==1;
    }
    int nthUglyNumber(int n) {
        int i = 0;
        int num = 0;
        while(i<n)
        {
            num++;
            if (isUgly(num))
            {
                i++;
            }
            
        }
        return num;
    }
};
```

### 方法二：动态规划
```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        int res =0;
        if (n<7)
            return n;
        vector<int> dp(n,0);
        dp[0] = 1;
        int l_2 = 0;
        int l_3 = 0;
        int l_5 = 0;
        for (int i=1;i<n;i++)
        {
            dp[i] = My_min(dp[l_2]*2,dp[l_3]*3,dp[l_5]*5);
            if (dp[l_2]*2<=dp[i])
                l_2++;
            if (dp[l_3]*3<=dp[i])
                l_3++;
            if (dp[l_5]*5<=dp[i])
                l_5++;
        }
        return dp[n-1];
    }

    int My_min(int a, int b, int c)
    {
        int res = min(a,b);
        res = min(res,c);
        return res;
    }
};
```

### 方法三：最小堆
```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long ,vector<long long>,greater<long>> min;
        min.push(1);
        long long res = 0;
        long long num = 0;
        vector<int> temp;
        for (int i=0;i<n;i++)
        {
            res = min.top();
            min.pop();
            while(!min.empty() && res == num)
            {
                res = min.top();
                min.pop();
            }
            num =res;
            min.push(res*2);
            min.push(res*3);
            min.push(res*5);
        }
        return res;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Ugly-Number-II/Ugly-Number-II.py)
###  方法一： 直接法（未通过OJ，超时）
```python
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <1:
            return False
        while num%5 == 0:
            num//=5
        while num%3 == 0:
            num//=3
        while num%2 == 0:
            num//=2
        return num==1
    def nthUglyNumber(self, n: int) -> int:
        i = 0
        num = 0
        while i<n:
            num+=1
            if self.isUgly(num):
                i+=1
        return num
```
###  方法二： 动态规划
```python
class Solution:
    def nthUglyNumber(self, n):
        # write code here
        if n<=0:
            return 0
        dp = [0 for _ in range(n)]
        dp[0] = 1
        l_2 = 0
        l_3 = 0
        l_5 = 0
        for i in range(1,n):
            dp[i] = min(dp[l_2]*2,dp[l_3]*3,dp[l_5]*5)
            if dp[l_2]*2<=dp[i]:
                l_2+=1
            if dp[l_3]*3<=dp[i]:
                l_3+=1
            if dp[l_5]*5<=dp[i]:
                l_5+=1
        return dp[n-1]
```

###  方法三： 小顶堆
```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        res = 0
        if n <= 0:
            return 0
        min_heap = []
        heapq.heappush(min_heap,1)
        for i in range(0,n):
            res = heapq.heappop(min_heap)
            while min_heap and res == min_heap[0]:
                res = heapq.heappop(min_heap)
            heapq.heappush(min_heap, res*2)
            heapq.heappush(min_heap, res*3)
            heapq.heappush(min_heap, res*5)
        return res
```

# 参考

  -  [丑数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Ugly-Number/README.md)
  -  [剑指Offer_49题丑数](https://github.com/bryceustc/CodingInterviews/blob/master/UglyNumber/README.md)




