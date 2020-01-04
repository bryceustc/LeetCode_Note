## Python2 Solution 1:
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

      
  ### Python2 Solution 2:
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
  ### Python3 solution 1:
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
  ### PYthon3 Solution 2: 
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
