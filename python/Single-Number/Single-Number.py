## Python Solution 1:
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_table = {}
        for num in nums:
            try:
                hash_table.pop(num)
            except:
                hash_table[num] = 1
        res = hash_table.popitem()[0]  ## Python 字典 popitem() 方法随机返回并删除字典中的最后一对键和值。如果字典已经为空，却调用了此方法，就报出KeyError异常。
        return res

## Python Solution 2:
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        res = 2*sum(set(nums)) - sum(nums)  ## set() 函数创建一个无序不重复元素集，可进行关系测试，删除重复数据，还可以计算交集、差集、并集等。
        return res
 

## Python Solution 3:
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res = res ^ num
        return res
