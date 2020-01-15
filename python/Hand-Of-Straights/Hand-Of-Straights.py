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
## Python Solution 2:
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
