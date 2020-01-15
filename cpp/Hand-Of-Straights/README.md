# 题目描述:  一手顺子

爱丽丝有一手（hand）由整数数组给定的牌。 

现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。

如果她可以完成分组就返回 true，否则返回 false。

**示例 1:**
```
输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
输出：true
解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
```
**示例 2:**
```
输入：hand = [1,2,3,4,5], W = 4
输出：false
解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
```

**提示** 
  1. 1 <= hand.length <= 10000
  2. 0 <= hand[i] <= 10^9
  3. 1 <= W <= hand.length

# 解题思路:
贪婪算法

我们用贪婪算法就可以了，首先从1开始，那么一定得有2和3，才能起连，若少了任何一个，都可以直接返回false，好那么取出这三张后，手里还有：

2 3 4 6 7 8

那么从当前手里的最小的牌2开始起连，那么手里必须要有3和4，若少了任何一个，都可以直接返回 false，好那么取出这三张后，手里还有：

6 7 8

从当前手里的最小的牌6开始起连，那么手里必须要有7和8，若少了任何一个，都可以直接返回 false，好那么取出这三张后，手里没牌了，我们成功的连完了所有的牌。分析这个过程，不难发现，由于牌可以重复，所以要统计每张牌出现的次数，同时还要给牌按大小排序，用 TreeMap 来建立牌的大小和其出现次数之间的映射就最好不过了，利用了其可以按 key 值排序的特点。首先遍历手中牌，建立映射。然后开始 while 循环，条件是 TreeMap 不为空，然后去除最小的那张牌，然后遍历能组成顺子的W张牌，若没有直接返回 true，有的话，则映射值自减1，若映射值为0了，则从 TreeMap 中移除该映射对儿即可，while 循环退出后返回 true
# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Hand-Of-Straights.cpp):

###  unordered_map基于哈希表 ，map基于红黑二叉树
```c++
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n%W!=0 || W<1 || W>n || hand.empty())
            return false;
        map<int, int> m;   // 有序哈希表
        for (auto card : hand)  
            m[card]++;
        while (!m.empty()) 
        {
            int start = m.begin()->first;// map 返回开始的关键值，也就是card的值
            for (int i = 0; i < W;i++) 
            {
                if (m.find(start + i)==m.end())  // 寻找start开始后的w个序列
                    return false;
                m[start+i]--;
                if (m[start + i] == 0) // 每找到一个满足的数字就删除
                    m.erase(start + i);
            }
        }
        return true;
    }
};
```

## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Hand-Of-Straights/Hand-Of-Straights.py)
###  哈希表 collections
```python
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        n = len(hand)
        if n%W!=0 or W<1 or W>n or n==0:
            return False
        count = collections.Counter(hand)
        ## print(count)
        ## Counter({2: 2, 3: 2, 1: 1, 6: 1, 4: 1, 7: 1, 8: 1})
        
        ## collections是Python内建的一个集合模块，提供了许多有用的集合类。
        ## Counter是一个简单的计数器，例如，统计字符出现的个数
        ## OrderedDict使用dict时，Key是无序的。在对dict做迭代时，我们无法确定Key的顺序。
        ## 如果要保持Key的顺序，可以用OrderedDict：
        
        while count:
            m = min(count)
            ## print (m)
            ## 1 2 6
            for k in range(m, m+W):
                v = count[k]
                if v == 0: 
                    return False
                if v == 1:
                    del count[k]
                else:
                    count[k] = v - 1
        return True
```
## 哈希表
```python
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        n = len(hand)
        if n%W!=0 or W<1 or W>n or n==0:
            return False
        d ={}
        for card in hand:
            d[card] = d.get(card,0) + 1  ## Python 字典 get() 函数返回指定键的值，如果值不在字典中返回默认值。
        nums = sorted(d.keys())
        for num in nums:
            if d[num] > 0:
                need = d[num]
                for i in range(W):
                    if d.get(num+i,0) >= need:
                        d[num+i] -= need
                    else:
                        return False
        return True
```

# 参考

  -  [C++中的STL中map用法详解](https://www.cnblogs.com/fnlingnzb-learner/p/5833051.html)、
  -  [C++ iterator->second意思](https://blog.csdn.net/aqzwss/article/details/42397843)
  -  [Python3 字典 get() 方法](https://www.runoob.com/python3/python3-att-dictionary-get.html)
  -  [Python从单元素字典中获取key和value](https://blog.csdn.net/qianghaohao/article/details/78994040)
  -  [Python 字典(Dictionary)](https://www.runoob.com/python/python-dictionary.html)
  -  [Python collections使用](https://www.liaoxuefeng.com/wiki/897692888725344/973805065315456)
